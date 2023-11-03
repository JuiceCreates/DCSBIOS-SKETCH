#define DCSBIOS_DEFAULT_SERIAL

#include <Arduino.h>
#include <DcsBios.h>

DcsBios::Potentiometer hmcsIntKnb("HMCS_INT_KNB", 15);

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  DcsBios::setup();
  Serial.begin(9600);
}

void loop() {
  DcsBios::loop();
    // read the input on analog pin GPIO36:
  int analogValue = analogRead(15);
  // Rescale to potentiometer's voltage (from 0V to 3.3V):
  float voltage = floatMap(analogValue, 0, 4095, 0, 3.3);

  // print out the value you read:
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);
  delay(1000);
}

