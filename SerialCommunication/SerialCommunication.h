#ifndef SerialCommunication_h
#define SerialCommunication_h
#include <SoftwareSerial.h>
#define byte uint8_t

//SoftwareSerial _mySerial(10, 11);
struct SerialData {
    char GetOrSet;
    int Function;
    int16_t Value;
    byte sender_address;

};

class SerialCommunication
{

  public:

    SerialCommunication(SoftwareSerial& serial,byte ownAddress,int RS485resvPin);
    SoftwareSerial&  _SoftSerial;
    void refresh();
    void begin();
    void sendData(int address,char getSet,int sensor,int16_t sensorValue);
    bool gotData();
    SerialData resvData;
  private:
    void fillSerialData();
    void flushData();

    int _RS485resvPin;

    byte _ownAddress;
    int _address;
    int _sensor;
    const int _numBytes = 6;
    byte _receivedBytes[7];
    byte _numReceived = 0;
    bool _newData = false;
    bool _useRS485=false;

};
#endif
