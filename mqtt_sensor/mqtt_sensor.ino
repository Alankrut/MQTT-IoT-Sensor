#include <AnalogSensor.h>
#include <CustomDHT.h>
#include <MotionSensor.h>
#include <MQTTClient.h>

#include "config.mine.h"

MQTTClient *mqttClient;
Sensor* listSensors[MAX_SENSORS];

void setup() {
  Serial.begin(9600);
  
  mqttClient = new MQTTClient(ssid, password, mqttServer, mqttUser, mqttPassword);
  mqttClient->setup();

  listSensors[0] = new MotionSensor(PIN_MOTION, topic_motion, frequency_motion, mqttClient);
  listSensors[1] = new AnalogSensor(PIN_LIGHT, topic_light, frequency_light, mqttClient);
  listSensors[2] = new CustomDHT(PIN_DHT, topic_temperature, topic_humidity, frequency_DHT, mqttClient);
}

void loop() {
    long now = millis();
    mqttClient->loop(now);

    for(int x = 0; x < MAX_SENSORS; x++){
        listSensors[x]->loop(now);
    }
}
