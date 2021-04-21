// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>


// The output pin of the DHT22
#define DHTPIN D2

// The type of the DHT sensor
#define DHTTYPE DHT22 // DHT 22 (AM2302)

// Initialise the DHT22 Sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    ;
}

void loop() {
    // Get the temperature and humidity
    float temp = dht.getTempCelcius();
    float humidity = dht.getHumidity();
    
    // Check if any reads failed and return to try again
    if (isnan(temp) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
	
    // Format a JSON string for use with a particle integration
    String data = String::format("{ \"temp\": \"%f\", \"humidity\": %f }", temp, humidity);

    // Publish to the integration
    Particle.publish("temp", data, PRIVATE);
	
    delay(30000);
}
