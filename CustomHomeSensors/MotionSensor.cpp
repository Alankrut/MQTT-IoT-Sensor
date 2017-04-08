#include "Arduino.h"
#include "MotionSensor.h"

MotionSensor::MotionSensor(int pin, const char* topic, long frequency, MQTTClient* client):Sensor(pin,topic, frequency, client) {
    _previousReading = LOW;
}

void MotionSensor::loop(long timeNow) {

    if (timeNow - _lastCheck < _frequency) {
        return;
    }

    _lastCheck = timeNow;
    int reading = digitalRead(_pin);
    processMotion(reading);
}

void MotionSensor::processMotion(int reading){
    if(_previousReading != reading){
        _previousReading = reading;
        if (reading == HIGH) {
            updateClient(true);
        } else{
            updateClient(false);
        }
    }
}

void MotionSensor::updateClient(bool detected){
    log(detected);
    _client->publish(_topic, detected?"ON":"OFF", true);
}

void MotionSensor::log(bool val){
    Serial.print("Publishing to MQTT: ");
    Serial.print(_topic);
    Serial.print(" ");
    Serial.println(val);
}