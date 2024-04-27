#define MQ135_PIN A0 // Analog pin connected to MQ135 AOUT

void setup() {
  Serial.begin(9600);
}

void loop() {
  float ppm = readMQ135();
  Serial.print("CO2 concentration: ");
  Serial.print(ppm);
  Serial.println(" ppm");
  delay(2000); // Adjust delay according to your needs
}

float readMQ135() {
  int sensorValue = analogRead(MQ135_PIN);
  float voltage = sensorValue * (3.3 / 1023.0); // Convert analog reading to voltage
  float ppm = voltageToPPM(voltage); // Convert voltage to ppm (parts per million)
  return ppm;
}

float voltageToPPM(float voltage) {
  // Replace these values with your calibration values
  float slope = -0.3462;
  float intercept = 1.3588;
  
  float ppm = slope * voltage + intercept;
  return ppm;
}