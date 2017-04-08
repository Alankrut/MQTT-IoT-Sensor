#ifndef config_h
#define config_h

const char* ssid = _SSID_;
const char* password = _PASS_;
const char* mqttServer = _MQTT_SERVER_;
const char* mqttUser = _USER_;
const char* mqttPassword = _PASS_;

const int MAX_SENSORS = 3;

const int PIN_LIGHT = A0;
const char* topic_light = "sensor/light";
const long frequency_light = 60000;

const int PIN_DHT = D3;
const char* topic_temperature = "sensor/temperature";
const char* topic_humidity = "sensor/humidity";
const long frequency_DHT = 60000;

const int PIN_MOTION = D0;
const char* topic_motion = "sensor/motion";
const long frequency_motion = 10;


#endif
