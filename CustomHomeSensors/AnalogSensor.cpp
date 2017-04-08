#include "Arduino.h"
#include "AnalogSensor.h"

AnalogSensor::AnalogSensor(int pin, const char* topic, long frequency, MQTTClient* client):Sensor(pin,topic, frequency, client) {
    
}

void AnalogSensor::loop(long timeNow) {

    if (timeNow - _lastCheck < _frequency) {
        return;
    }

    _lastCheck = timeNow;
    int val = analogRead(_pin);
  
    log(val);
    _client->publish(_topic, String(val).c_str(), true);
}

void AnalogSensor::log(int val){
    Serial.print("Publishing to MQTT: ");
    Serial.print(_topic);
    Serial.print(" ");
    Serial.println(val);
}