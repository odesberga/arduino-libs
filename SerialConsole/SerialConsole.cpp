#include <SerialConsole.h>


SerialConsole::SerialConsole(HardwareSerial& serial): _Serial(serial){



}
void SerialConsole::begin(int baud){
    _Serial.begin(baud);
    _Serial.print("init");
}
