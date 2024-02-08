#include "EspMQTTClient.h"
#include "DHTesp.h"
#include <AccelStepper.h>

AccelStepper stepper1(AccelStepper::FULL4WIRE, 13, 12, 14, 27);
EspMQTTClient client("Wokwi-GUEST", "", "test.mosquitto.org", "mqtt-mack-pub-sub", 1883);
const int DHT_PIN = 15;
DHTesp dhtSensor;

void setup() {
    stepper1.setMaxSpeed(8000);
    Serial.begin(115200);
    dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
    client.enableDebuggingMessages();
}

unsigned long lastSendTime = 0;
const unsigned long sendInterval = 2000;

void readSendData() {
    unsigned long currentTime = millis();
    if (currentTime - lastSendTime >= sendInterval) {
        TempAndHumidity data = dhtSensor.getTempAndHumidity();
        String jsonData = "{\"temperature\":" + String(data.temperature, 2) + ",\"humidity\":" + String(data.humidity, 2) + "}";
        client.publish("chad/env", jsonData);
        lastSendTime = currentTime;
    }
}


float calculateComfortIndex(float temperature, float humidity) {
    return (0.7 * temperature) + (0.3 * humidity);
}

void controlFanSpeed(float temperature, float humidity) {
    float comfortIndex = calculateComfortIndex(temperature, humidity);
    if (comfortIndex < 30) {
        stepper1.setSpeed(0);
    } else if (comfortIndex >= 30 && comfortIndex < 40) {
        stepper1.setSpeed(500);
    } else if (comfortIndex >= 40 && comfortIndex < 50) {
        stepper1.setSpeed(1000);
    } else if (comfortIndex >= 50 && comfortIndex < 60) {
        stepper1.setSpeed(1500);
    } else if (comfortIndex >= 60) {
        stepper1.setSpeed(2000);
    }
    stepper1.runSpeed();
}

void onConnectionEstablished() {
}

void loop() {
    client.loop();
    TempAndHumidity data = dhtSensor.getTempAndHumidity();
    controlFanSpeed(data.temperature, data.humidity);
    readSendData();
}