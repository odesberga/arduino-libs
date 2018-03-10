#include "Arduino.h"
#include <SoftwareSerial.h>
#include "SerialCommunication.h"
#define RS485Transmit    HIGH
#define RS485Receive     LOW
//#define uint8_t byte

SerialCommunication::SerialCommunication(SoftwareSerial &serial,byte ownAddress,int RS485resvPin) : _SoftSerial(serial)
{
    _ownAddress=ownAddress;
    _RS485resvPin=RS485resvPin;

    if (RS485resvPin > 0){
        _useRS485=true;
        pinMode(RS485resvPin, OUTPUT);
        digitalWrite(RS485resvPin, RS485Receive);
    }
    else
    {
        _useRS485=false;
    }
}
void SerialCommunication::begin(){
    _SoftSerial.begin(19200);
    _SoftSerial.print("init");
}

void SerialCommunication::refresh(){
    static boolean recvInProgress = false;
        static byte ndx = 0;
        byte startMarker = '!';
        byte endMarker = '#';
        byte rb;
        while (_SoftSerial.available() > 0 && _newData == false) {
            rb = _SoftSerial.read();
            if (recvInProgress == true) {
                if (rb != endMarker) {
                    _receivedBytes[ndx] = rb;
                    ndx++;
                    if (ndx >= _numBytes) {
                        ndx = _numBytes - 1;
                    }
                }
                else {
                    recvInProgress = false;
                    ndx = 0;
                    if (_useRS485) {
                        if (_receivedBytes[0] == _ownAddress){
                        _newData = true;

                        }
                        else
                        {
                         flushData();
                         _newData = false;
                        }
                    }
                    else
                    {
                        _newData = true;
                    }
                }
                if(_newData){
                    fillSerialData();
                }
            }
            else if (rb == startMarker) {
                recvInProgress = true;
            }
        }
}
void SerialCommunication::sendData(int address,char getSet,int sensor,int16_t sensorValue){

    if (_useRS485) digitalWrite(_RS485resvPin, RS485Transmit);
    _SoftSerial.write('!');
    _SoftSerial.write(address);
    _SoftSerial.write(getSet);
    _SoftSerial.write(sensor);
    //_SoftSerial.write(sensorValue/256);
    //_SoftSerial.write(sensorValue % 256);
    //_SoftSerial.write(highByte(sensorValue));
    _SoftSerial.write((uint8_t)sensorValue);
    sensorValue >>= 8;
    _SoftSerial.write((uint8_t)sensorValue);
    _SoftSerial.write(_ownAddress);
    _SoftSerial.write('#');
    if (_useRS485)digitalWrite(_RS485resvPin, RS485Receive);
}
bool SerialCommunication::gotData(){
refresh();
bool a = _newData;
_newData =false;
if (a) return true; else return false;

}

void SerialCommunication::flushData(){
memset(_receivedBytes, 0, sizeof(_receivedBytes));
}
void  SerialCommunication::fillSerialData(){
byte buf[] = {_receivedBytes[3],_receivedBytes[4]};
resvData.GetOrSet = char(_receivedBytes[1]);
resvData.Function = _receivedBytes[2];
//resvData.Value =(int16_t)_receivedBytes[3]*256+_receivedBytes[4];
resvData.Value = _receivedBytes[3];
resvData.Value +=_receivedBytes[4] << 8;

//resvData.Value =_receivedBytes[3];
resvData.sender_address=_receivedBytes[5];
}
