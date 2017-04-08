/*
    genericAnalogSensor_h - Library class for an analog sensor
*/
#ifndef AnalogSensor_h
#define AnalogSensor_h

#include "Sensor.h"
#include "MQTTClient.h"
#include "Arduino.h"


class AnalogSensor : public Sensor {
  public:
    AnalogSensor(int pin, const char* topic, long frequency, MQTTClient* client);
    virtual void loop(long timeNow);
    virtual void log(int val);
};

#endif
