#define WATER_SENSOR_PIN A0 // Analog pin connected to water sensor output

void setup() {
  Serial.begin(9600);
}

void loop() {
  float waterLevel = readWaterLevel();
  Serial.print("Water level: ");
  Serial.print(waterLevel);
  Serial.println(" inches");
  delay(2000); // Adjust delay according to your needs
}

float readWaterLevel() {
  int sensorValue = analogRead(WATER_SENSOR_PIN);
  float voltage = sensorValue * (5.0 / 1023.0); // Convert analog reading to voltage
  float level = voltageToInches(voltage); // Convert voltage to water level (in inches)
  return level;
}

float voltageToInches(float voltage) {
  // Replace these values with your calibration values
  float slope = 5.0; // Example calibration slope
  float intercept = 0.0; // Example calibration intercept
  
  float level = slope * voltage + intercept;
  return level;
}