#ifndef MotionSensor_h
#define MotionSensor_h

#include "Sensor.h"
#include "MQTTClient.h"
#include "Arduino.h"


class MotionSensor : public Sensor {
  public:
    MotionSensor(int pin, const char* topic, long frequency, MQTTClient* client);
    virtual void loop(long timeNow);
    virtual void processMotion(int reading);
    virtual void updateClient(bool detected);
    virtual void log(bool val);

  private:
    int _previousReading;
};

#endif
