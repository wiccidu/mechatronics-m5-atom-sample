#include <M5Atom.h>
void setup() {
    M5.begin(true, false, true);
    delay(50);
}

void loop() {
    if(Serial.available() > 0) { 
        char data = Serial.read(); 
        Serial.print(data); 
    } 
}
