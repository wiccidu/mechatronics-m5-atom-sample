#include <M5Atom.h>
void setup() {
    M5.begin(true, false, true);
    delay(50);
}

void loop() {
    Serial.println("HelloAtom");
    delay(1000); 
}
