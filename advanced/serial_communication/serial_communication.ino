#include <M5Atom.h>

String SSID = "";
String PASS = "";

void setup() {
    M5.begin(true, false, true);
    delay(50);
}

void loop() {
    checkSerial();
}

void checkSerial(){
    if(Serial.available() > 0) { 
        String data = Serial.readString();
        Serial.print(data); 
        if (data.indexOf("$") == 0){
            Serial.println("Start wifi settings."); 
            Serial.print("Input SSID:");
            while(true) {
                if(Serial.available() > 0) {
                    break;
                }
                delay(100);
            }
            SSID = Serial.readString();
            Serial.print(SSID);
            Serial.print("Input PASS:");
            while(true) {
                if(Serial.available() > 0) {
                    break;
                }
                delay(100);
            }
            PASS = Serial.readString();
            Serial.print(PASS);
            Serial.println("Finished wifi settings.");
        }
    } 
}
