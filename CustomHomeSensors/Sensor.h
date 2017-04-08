/*
    genericAnalogSensor_h - Library class for an analog sensor
*/
#ifndef Sensor_h
#define Sensor_h

#include "MQTTClient.h"
#include "Arduino.h"

//Abstract class Sensor
class Sensor
{
  public:
    Sensor(int pin, const char* topic, long frequency, MQTTClient* client){
        _pin = pin;
        _lastCheck = 0;
        _topic = topic;
        _frequency = frequency;
        _client = client;
        pinMode(_pin, INPUT);
    }
    
    virtual void loop(long timeNow) = 0;

    int _pin;
    long _frequency;
    long _lastCheck;
    const char *_topic;
    MQTTClient *_client;
};

#endif
