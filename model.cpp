#include <DHT.h>
#include <DHT_U.h>

// Define pin connections
#define DHTPIN 2
#define SOIL_MOISTURE_PIN A0
#define RELAY_PIN 3

// Define sensor types
#define DHTTYPE DHT11

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();

  // Set relay pin as output
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // Read soil moisture value
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

  // Read temperature and humidity values
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Print sensor values to serial monitor
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Temperature: ");
  Serial.println(temperature);

  // Define threshold values
  int soilMoistureThreshold = 600; // Adjust as per your sensor calibration

  // Control the relay based on soil moisture threshold
  if (soilMoistureValue < soilMoistureThreshold) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on the pump
    Serial.println("Pump ON");
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off the pump
    Serial.println("Pump OFF");
  }

  // Delay for a while before next reading
  delay(2000);
}
