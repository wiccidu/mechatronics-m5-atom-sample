#include <stdint.h>
#include <M5Atom.h>
#include "BluetoothSerial.h"
#include <Wire.h>

#define ADS1115_I2C_ADDRESS         0x48

#define CONVERSION_REGISTER         0
#define CONFIG_REGISTER             1
#define LO_THRESH_REGISTER          2
#define HI_THRESH_REGISTER          3

#define NO_EFFECT                   0b0000000000000000
#define START_SINGLE_CONVERSION     0b1000000000000000

#define P_AIN0_N_AIN1               0b0000000000000000
#define P_AIN0_N_AIN3               0b0001000000000000
#define P_AIN1_N_AIN3               0b0010000000000000
#define P_AIN2_N_AIN3               0b0011000000000000
#define P_AIN0_N_GND                0b0100000000000000
#define P_AIN1_N_GND                0b0101000000000000
#define P_AIN2_N_GND                0b0110000000000000
#define P_AIN3_N_GND                0b0111000000000000

#define FSR_6144MV                  0b0000000000000000
#define FSR_4096MV                  0b0000001000000000
#define FSR_2048MV                  0b0000010000000000
#define FSR_1024MV                  0b0000011000000000
#define FSR_0512MV                  0b0000100000000000
#define FSR_0256MV                  0b0000101000000000

#define CONTINUOUS_CONVERSION       0b0000000000000000
#define SINGLE_SHOT                 0b0000000100000000

#define DATA_RATE_8_SPS             0b0000000000000000
#define DATA_RATE_16_SPS            0b0000000000100000
#define DATA_RATE_32_SPS            0b0000000001000000
#define DATA_RATE_64_SPS            0b0000000001100000
#define DATA_RATE_128_SPS           0b0000000010000000
#define DATA_RATE_250_SPS           0b0000000010100000
#define DATA_RATE_475_SPS           0b0000000011000000
#define DATA_RATE_860_SPS           0b0000000011100000

#define TRADITIONAL_COMPARATE       0b0000000000000000
#define WINDOW_COMPARATE            0b0000000000010000

#define ACTIVE_LOW                  0b0000000000000000
#define ACTIVE_HIGH                 0b0000000000001000

#define NONLATCHING_COMPARATOR      0b0000000000000000
#define LATCHING_COMPARATOR         0b0000000000000100

#define ASSERT_AFTER_1_CONVERSION   0b0000000000000000
#define ASSERT_AFTER_2_CONVERSION   0b0000000000000001
#define ASSERT_AFTER_4_CONVERSION   0b0000000000000010
#define DISABLE_COMPARATOR          0b0000000000000011


#define RED     0
#define GREEN   1
#define BLUE    2
#define CYAN    3
#define MAGENTA 4
#define YELLOW  5
#define WHITE   6

#define ADC_TYPE_INNER  0
#define ADC_TYPE_I2C    1


uint16_t ads1115_read_register(uint8_t register_address);
void ads1115_write_register(uint8_t register_address, uint16_t register_data);
char line_buffer[64];

const String BT_NAME = "AtomTestBoard";

const int SAMPLING_FREQ = 200; //[Hz]
const int BASE_DELAY = 1000000/SAMPLING_FREQ; //[usec]
const int AD_INPUT = 33;

bool sendFlag = true;
int adc_type = ADC_TYPE_I2C;

BluetoothSerial SerialBT;

void setupADS1115() {
   Wire.begin(25, 21);
   Serial.begin(115200);
   ads1115_write_register(LO_THRESH_REGISTER, 0x1000);
   ads1115_write_register(HI_THRESH_REGISTER, 0xA000);
   ads1115_write_register(CONFIG_REGISTER, NO_EFFECT
                                         | P_AIN0_N_GND
                                         | FSR_2048MV
                                         | CONTINUOUS_CONVERSION
                                         | DATA_RATE_250_SPS
                                         | WINDOW_COMPARATE
                                         | ACTIVE_LOW
                                         | LATCHING_COMPARATOR
                                         | ASSERT_AFTER_1_CONVERSION);
    Serial.println("---------------");
    sprintf(line_buffer, "CONFIG_REGISTER: 0x%04x", ads1115_read_register(CONFIG_REGISTER));
    Serial.println(line_buffer);
}

void setup() {
    M5.begin(true, false, true);
    SerialBT.begin(BT_NAME);
    delay(50);
    SerialBT.println("Start SerialBT");
    setupADS1115();
}

void loop() {
    SerialCheck();
    ButtonCheck();
    if (sendFlag)
    {
        long t = micros();
        int i = 0;
        if (adc_type == ADC_TYPE_INNER)
        {
            i = analogRead(AD_INPUT);
        }else if(adc_type == ADC_TYPE_I2C){
            i = (int)ads1115_read_register(CONVERSION_REGISTER);
        }
        SerialBT.println(i);
        int delaymsec = BASE_DELAY-(micros()-t);
        if (delaymsec > 0)
        {
            delayMicroseconds(delaymsec);
        }
    }
    updateLED();
    M5.update();
}

void SerialCheck(){
    if(SerialBT.available() > 0) {
        String data = SerialBT.readString();
        SerialBT.println(data);
        if (data == "start\n"){
            sendFlag = true;
        } else if (data == "end\n"){
            sendFlag = false;
        }
        if (data == "inner\n"){
            adc_type=ADC_TYPE_INNER;
        } else if (data == "i2c\n"){
            adc_type=ADC_TYPE_I2C;
        }
    }
}

void ButtonCheck(){
     if (M5.Btn.wasReleased()) {
        sendFlag = !sendFlag;
     }
}

void updateLED(){
    if (sendFlag){
        LED(BLUE);
    } else {
        LED(RED);
    }
}

void LED(int c){
    switch (c) {
        case 0:
            M5.dis.drawpix(0, 0x700000);
            break;
        case 1:
            M5.dis.drawpix(0, 0x007000);
            break;
        case 2:
            M5.dis.drawpix(0, 0x000070);
            break;
        case 3:
            M5.dis.drawpix(0, 0x700070);
            break;
        case 4:
            M5.dis.drawpix(0, 0x007070);
            break;
        case 5:
            M5.dis.drawpix(0, 0x707000);
            break;
        case 6:
            M5.dis.drawpix(0, 0x707070);
            break;
        default:
            M5.dis.drawpix(0, 0x000000);
            break;
    }
}


uint16_t ads1115_read_register(uint8_t register_address) {
    uint16_t dat, byte_count;

    Wire.beginTransmission(ADS1115_I2C_ADDRESS);
    Wire.write(register_address);
    Wire.endTransmission();

    byte_count = Wire.requestFrom(ADS1115_I2C_ADDRESS, 2);
    dat = Wire.read() << 8 | Wire.read();
    return(dat);
}

void ads1115_write_register(uint8_t register_address, uint16_t register_data){
    Wire.beginTransmission(ADS1115_I2C_ADDRESS);
    Wire.write(register_address);
    Wire.write((register_data >> 8 ) & 0b11111111);
    Wire.write((register_data >> 0 ) & 0b11111111);
    Wire.endTransmission();
}

