/*
    CustomDHT_h - Library class for an analog sensor
*/
#ifndef CustomDHT_h
#define CustomDHT_h

#include "Sensor.h"
#include "MQTTClient.h"
#include "Arduino.h"

#include<DHT.h>

class CustomDHT : public Sensor
{
  public:
    CustomDHT(int pin, const char *_topicTemperature, const char *_topicHumidity, long frequency, MQTTClient* client);
    virtual void loop(long timeNow);
    virtual void log(float temperature, float humidity);

  private:
    const char *_topicHumidity;
    DHT *_dht;
};

#endif
