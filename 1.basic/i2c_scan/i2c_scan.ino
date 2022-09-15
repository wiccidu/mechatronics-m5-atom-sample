#include <Wire.h>

void setup()
{
  Serial.begin(115200);
  Wire.begin(25, 21);
}

void loop()
{
  Serial.println("I2C Scan");
  for (int address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    int error = Wire.endTransmission();
    if (error == 0) {
      Serial.printf("%02X", address);
    } else {
      Serial.print(" .");
    }

    if (address % 16 == 0) {
      Serial.print("\n");
    }

    delay(10);
  }

  Serial.print("\n\n");
  delay(1000);
}