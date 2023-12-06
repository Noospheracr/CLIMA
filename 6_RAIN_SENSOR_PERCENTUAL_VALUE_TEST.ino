const int sensor_pin = A0;  /* Connect RAIN analog sensor pin to A0 of NodeMCU */

void setup() {
  Serial.begin(115200); /* Define baud rate for serial communication */
}

void loop() {
  float rain_percentage;

  rain_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("Light(in Percentage) = ");
  Serial.print(rain_percentage);
  Serial.println("%");

  delay(1000);
}