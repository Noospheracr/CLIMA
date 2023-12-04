#include <Wire.h>
#include <ArduinoJson.h>		// Json libraries are imported to create the JSON string to be sent to AWS

void setup() {
  Serial.begin(115200); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int rain = analogRead(A0);     // Reads the input on analog pin A0, and stores it in RAIN.
// Create a JSON object
  StaticJsonDocument<200> doc;
  doc["rain"] = rain;

  // Serialize JSON to string
  String output;
  serializeJson(doc, output);

  // Print to Serial
  Serial.println(output);

  // Send data to AWS
  sendDataToAWS(output);

  // Delay for 0.4 seconds (400 milliseconds)
  delay(400);
}

void sendDataToAWS(String data) {
  Serial.print(".");
  // Use AT commands to send data to AWS
  // Example: AT+CIPSTART="TCP","your.api.endpoint",port
  // Example: AT+CIPSEND=...
  // Send your HTTP request with data
}
