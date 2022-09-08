#include <M5Atom.h>

const int INPUT_PIN  = 33;
const int OUTPUT_PIN = 33;

void setup() {
    Serial.begin(115200);
    M5.begin(true, false, true);
    pinMode(INPUT_PIN, INPUT);
    pinMode(OUTPUT_PIN, OUTPUT);
    delay(50);
}

void loop() {
    int i = digitalRead(INPUT_PIN);
    Serial.println(i);
    digitalWrite(OUTPUT_PIN, i);
    delay(1000); 
}
