#include <SensorHandler.h>
#include "Arduino.h"


SensorHandler::SensorHandler(int count){

};

void SensorHandler::add(char * SensorStr){
  char intBuffer[6];
  int commacount=0;
  int idx=0;
  int j=0;
  int emptySensoridx=0;
            j=SensorCount;
            SensorCount++;
            for (int i =0; i< 61;i++){
                if (SensorStr[i]=='\0'){
                    break;};
                if (SensorStr[i]==','){
                  commacount++;
                  idx=0;
                  memset(intBuffer, 0, 6);
                } else {
                  switch (commacount) {
                    case 0:
                    if (idx<=NameLength)
                      _SensorData[j].SensorName[idx] = SensorStr[i];
                      break;
                    case 1:
                        intBuffer[idx]= SensorStr[i];
                        intBuffer[idx+1]= '\0';
                        _SensorData[j].SensorAddress = atoi(intBuffer);
                      break;
                    case 2:
                    intBuffer[idx]= SensorStr[i];
                    intBuffer[idx+1]= '\0';
                    _SensorData[j].SensorFunction = atoi(intBuffer);
                        break;
                    case 3:
                        intBuffer[idx]= SensorStr[i];
                        intBuffer[idx+1]= '\0';
                        _SensorData[j].SensorThreshold = atoi(intBuffer);
                        break;
                    case 4:
                        _SensorData[j].ThresholdPosNeg = SensorStr[i];
                        break;
                    case 5:
                        _SensorData[j].Alarmlevel = SensorStr[i];
                        break;
                    case 6:
                        _SensorData[j].PrintToScreen = SensorStr[i];
                        break;
                    case 7:
                        intBuffer[idx]= SensorStr[i];
                        intBuffer[idx+1]= '\0';
                        _SensorData[j].ForwardSensorAddress = atoi(intBuffer);
                        break;
                    case 8:
                        intBuffer[idx]= SensorStr[i];
                        intBuffer[idx+1]= '\0';
                        _SensorData[j].ForwardSensorFunction = atoi(intBuffer);
                        break;
                  }
                  idx++;
                }
            }
}


SensorData SensorHandler::getSensor(uint8_t Address,uint8_t Function){
for (int j =0; j< SensorCount+1;j++){
    if ((_SensorData[j].SensorAddress==Address) && (_SensorData[j].SensorFunction==Function)){
        return _SensorData[j];
        break;}
    }
}
int SensorHandler::sensorCount() {return SensorCount;};
