#include <M5Atom.h>
#include "BluetoothSerial.h"

const int SAMPLING_FREQ = 100; //[Hz]
const int BASE_DELAY = 1000000/SAMPLING_FREQ; //[usec]
const int AD_INPUT = 33;

BluetoothSerial SerialBT;

void setup() {
    M5.begin(true, false, true);
    SerialBT.begin("ESP32");
    delay(50);
    SerialBT.println("Hello World");
}

void loop() {
    long t = micros();
    int i = analogRead(AD_INPUT);
    SerialBT.println(i);
    delayMicroseconds(BASE_DELAY-(micros()-t));
}
