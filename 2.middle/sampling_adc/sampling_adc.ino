#include <M5Atom.h>
const int SAMPLING_FREQ = 100; //[Hz]
const int BASE_DELAY = 1000000/SAMPLING_FREQ; //[usec]
const int AD_INPUT = 33;

void setup() {
    Serial.begin(115200);
    M5.begin(true, false, true);
    delay(50);
}

void loop() {
    long t = micros();
    int i = analogRead(AD_INPUT);
    Serial.println(i);
    delayMicroseconds( BASE_DELAY - (micros() - t));
}
