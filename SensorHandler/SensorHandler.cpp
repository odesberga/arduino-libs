#include <SensorHandler.h>
#include "Arduino.h"


SensorHandler::SensorHandler(int count){

};

void SensorHandler::add(char * SensorStr){

  char intBuffer[6];
  int commacount=0;
  int idx=0;
  int emptySensoridx=0;
  for (int j =0; j< 101;j++){
      if (_SensorData[j].SensorAddress =0) {
            SensorCount++;
            for (int i =0; i< strlen(SensorStr)-1;i++){
                if (SensorStr[i]=='\0'){break;};
                if (SensorStr[i]==','){
                  commacount++;
                  idx=0;
                  memset(intBuffer, 0, sizeof(intBuffer));
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
                        _SensorData[j].SensorFunction = SensorStr[i];
                        break;
                    case 3:
                        intBuffer[idx]= SensorStr[i];
                        intBuffer[idx+1]= '\0';
                        _SensorData[j].SensorThreshold = atoi(intBuffer);
                        break;
                    case 4:
                        intBuffer[idx]= SensorStr[i];
                        intBuffer[idx+1]= '\0';
                        _SensorData[j].Alarmlevel = atoi(intBuffer);
                        break;
                    case 5:
                        _SensorData[j].PrintToScreen = SensorStr[i];
                        break;
                    case 6:
                        intBuffer[idx]= SensorStr[i];
                        intBuffer[idx+1]= '\0';
                        _SensorData[j].ForwardSensorAddress = atoi(intBuffer);
                        break;
                    case 7:
                        intBuffer[idx]= SensorStr[i];
                        intBuffer[idx+1]= '\0';
                        _SensorData[j].ForwardSensorFunction = atoi(intBuffer);
                        break;
                  }
                  idx++;
                }
            }




      }
      break;
  }
}


SensorData SensorHandler::getSensor(int Address){
for (int j =0; j< 101;j++){
if (_SensorData[j].SensorAddress==Address) return _SensorData[j];
}


}
