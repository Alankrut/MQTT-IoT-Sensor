# MQTT IoT Sensor

Welcome! This project is for using an ESP8266 as a MQTT based IoT sensor. It has configurations to allow you to use multiple sensors on the same microchip, these can be modified easily using config file and a simple code change.
Included is a custom library (which you will have to import into Arduino IDE's library folder) and then the sketch will work out of the box.

## Adding Sensors

Update `config.h` with the number of sensors you will be using

```
const int MAX_SENSORS = 3;
```

for each sensor you are planning to use, make sure you add the following configuration
```
const int PIN_LIGHT = A0;
const char* topic_light = "sensor/light";
const long frequency_light = 60000;
```

Now before moving on, lets go over each of these fields for a second
```
PIN_LIGHT = The pin at which the sensor is connected, the light is just to help you know which sensor
TOPIC_LIGHT = The topic this sensor should post to on the MQTT server
FREQUENCY_LIGHT = The frequency in milliseconds at which this sensor should be polled
```

Update `mqtt_all3.ino` to use the sensors we want.
Currently 3 sensors are set up, shown bellow. 
```
listSensors[0] = new MotionSensor(PIN_MOTION, topic_motion, frequency_motion, mqttClient);
listSensors[1] = new AnalogSensor(PIN_LIGHT, topic_light, frequency_light, mqttClient);
listSensors[2] = new CustomDHT(PIN_DHT, topic_temperature, topic_humidity, frequency_DHT, mqttClient);
```
If adding an additional sensor, just make a new object at the next index of the array. Use the library to determine which object type the sensor should be

## Removing Sensors

Removing is done the same way as [adding a sensor](https://github.com/Alankrut/ESP8266Sensor/new/master?readme=1#adding-sensors), but by simply doing the opposite (Reduce the `MAX_SENSORS` count and remove the section in the config/code for that sensor)
