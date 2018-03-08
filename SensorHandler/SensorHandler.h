#ifndef SensorHandler_h
#define SensorHandler_h
#include <Arduino.h>
#include <stdint.h>
#define byte uint8_t
#define NameLength 10
struct SensorData {
    char SensorName[NameLength];
    byte SensorAddress=0;
    byte SensorFunction=0;
    int16_t SensorThreshold=0;
    char ThresholdPosNeg=0;
    char Alarmlevel=0;
    char PrintToScreen=0;
    byte ForwardSensorAddress=0;
    byte ForwardSensorFunction=0;
    int16_t LastValue=0;
};


class SensorHandler
{

  public:
    SensorHandler(int count);
    void add(char * SensorStr);
    SensorData getSensor(int Address);
    int SensorCount=0;
  private:
     SensorData _SensorData[100];

};






#endif
