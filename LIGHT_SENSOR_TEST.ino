#include <Wire.h>

const int photoSensorPin = D3; // Photosensor connected to D3

void setup() {
  Serial.begin(115200); // Start Serial communication
  pinMode(photoSensorPin, INPUT); // Set D3 as an input
}

void loop() {
  int sensorValue = digitalRead(photoSensorPin); // Read the sensor value
  Serial.print("Photosensor Value: ");
  Serial.println(sensorValue); // Print the value (HIGH or LOW)
  delay(1000); // Delay for readability
}