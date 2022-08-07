#include "M5Atom.h"

const int AD_INPUT = 33;

void setup() {
    Serial.begin(115200);
    M5.begin(true, false, true);
    delay(50);
}

void loop() {
    int i = analogRead(AD_INPUT);
    Serial.println(i);
    delay(1000); 
}
