#include "Arduino.h"
#include "CustomDHT.h"

CustomDHT::CustomDHT(int pin, const char* topicTemperature, const char* topicHumidity, long frequency, MQTTClient* client):Sensor(pin,topicTemperature, frequency, client) {
  _topicHumidity = topicHumidity;
  _dht = new DHT(pin, DHT11);
}

void CustomDHT::loop(long timeNow) {

    if (timeNow - _lastCheck < _frequency) {
        return;
    }

    _lastCheck = timeNow;
    float temperature = _dht->readTemperature(true);
    float humidity = _dht->readHumidity();
    
    log(temperature, humidity);
    _client->publish(_topic, String(temperature).c_str(), true);
    _client->publish(_topicHumidity, String(humidity).c_str(), true);
}

void CustomDHT::log(float temperature, float humidity){

    Serial.print("Publishing to MQTT: ");
    Serial.print(_topic);
    Serial.print(" ");
    Serial.println(temperature);
    
    Serial.print("Publishing to MQTT: ");
    Serial.print(_topicHumidity);
    Serial.print(" ");
    Serial.println(humidity);

}