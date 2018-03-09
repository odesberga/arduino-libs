#ifndef SerialConsole_h
#define SerialConsole_h
#include <SoftwareSerial.h>
#include <avr/pgmspace.h>
#include<Arduino.h>


const char HelpMenu_string_0[] PROGMEM = "Help Menu!";
const char HelpMenu_string_1[] PROGMEM = "Sensors:";
const char HelpMenu_string_2[] PROGMEM = "list sensors :List Sensors";
const char HelpMenu_string_3[] PROGMEM = "delsensor [sensor] :Remove Sensor";
const char HelpMenu_string_4[] PROGMEM = "addsensor [sensorname]  :Start add new sensor wizard";
const char HelpMenu_string_5[] PROGMEM = "";
const char HelpMenu_string_6[] PROGMEM = "Alarms:";
const char HelpMenu_string_7[] PROGMEM = "list alarmnumbers :List telephone numbers";
const char HelpMenu_string_8[] PROGMEM = "setalarm [sensor] [value] [Pos/Neg] :Set sensor error Threshold value + -";
const char HelpMenu_string_9[] PROGMEM = "addalarmnumber [alarm level] [phone number] :Add a telephone number to alarm level";
const char HelpMenu_string_10[] PROGMEM = "delalarmnumber [alarm level] [phone number] :Add a telephone number to alarm level";
const char HelpMenu_string_11[] PROGMEM = "";
const char HelpMenu_string_12[] PROGMEM = "changeip [ipnumber]   :Change IP (If using ethernet shield)";
const char HelpMenu_string_13[] PROGMEM = "";
const char HelpMenu_string_14[] PROGMEM = "debug [on/off]   :start / stop serial debugging)";



const char* const menu_help[] PROGMEM = {
    HelpMenu_string_0, HelpMenu_string_1, HelpMenu_string_2, HelpMenu_string_3, HelpMenu_string_4, HelpMenu_string_5
    , HelpMenu_string_6, HelpMenu_string_7, HelpMenu_string_8, HelpMenu_string_9, HelpMenu_string_10, HelpMenu_string_11
    , HelpMenu_string_12, HelpMenu_string_13, HelpMenu_string_14
};



class SerialConsole
{

  public:

    SerialConsole(HardwareSerial& serial);
    HardwareSerial&  _Serial;
    void refresh();
    void begin(int baud);
    private:




};





#endif
