#include <M5Atom.h>
#include "BluetoothSerial.h"

#define RED     0
#define GREEN   1
#define BLUE    2
#define CYAN    3
#define MAGENTA 4
#define YELLOW  5
#define WHITE   6

const int SAMPLING_FREQ = 200; //[Hz]
const int BASE_DELAY = 1000000/SAMPLING_FREQ; //[usec]
const int AD_INPUT = 33;

bool sendFlag = true;

BluetoothSerial SerialBT;

void setup() {
    M5.begin(true, false, true);
    SerialBT.begin("ESP32");
    delay(50);
    SerialBT.println("Hello World");
    LED(BLUE);
}

void loop() {
    SerialCheck();
    ButtonCheck();
    if (sendFlag)
    {
        long t = micros();
        int i = analogRead(AD_INPUT);
        SerialBT.println(i);
        delayMicroseconds(BASE_DELAY-(micros()-t));
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
