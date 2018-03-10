#ifndef SerialConsole_h
#define SerialConsole_h
#include <SensorHandler.h>
#include <SoftwareSerial.h>
#include <avr/pgmspace.h>
#include<Arduino.h>

#define helpmenu_count 15
const char HelpMenu_string_0[] PROGMEM = "Help Menu!";
const char HelpMenu_string_1[] PROGMEM = "Sensors:";
const char HelpMenu_string_2[] PROGMEM = "sensor list :List Sensors";
const char HelpMenu_string_3[] PROGMEM = "sensor del [sensorname] :Remove Sensor.";
const char HelpMenu_string_4[] PROGMEM = "sensor add [sensorname] :add new sensor (wizard)";
const char HelpMenu_string_5[] PROGMEM = "";
const char HelpMenu_string_6[] PROGMEM = "Alarms:";
const char HelpMenu_string_7[] PROGMEM = "alarmnumber list :List telephone numbers";
const char HelpMenu_string_8[] PROGMEM = "alarmnumber add [alarm level] [phone number] :Add a telephone number to alarm level";
const char HelpMenu_string_9[] PROGMEM = "alarmnumber del [alarm level] [phone number] :Delete a telephone number from alarm level";
const char HelpMenu_string_10[] PROGMEM = "setalarm [sensor] [value] [Pos/Neg] :Set sensor error Threshold value + -";
const char HelpMenu_string_11[] PROGMEM = "";
const char HelpMenu_string_12[] PROGMEM = "changeip [ipnumber]   :Change IP (If using ethernet shield)";
const char HelpMenu_string_13[] PROGMEM = "reboot : Restart the system";
const char HelpMenu_string_14[] PROGMEM = "debug [on/off]   :start / stop serial debugging)";
const char* const menu_help[] PROGMEM = {
    HelpMenu_string_0, HelpMenu_string_1, HelpMenu_string_2, HelpMenu_string_3, HelpMenu_string_4, HelpMenu_string_5
    , HelpMenu_string_6, HelpMenu_string_7, HelpMenu_string_8, HelpMenu_string_9, HelpMenu_string_10, HelpMenu_string_11
    , HelpMenu_string_12, HelpMenu_string_13, HelpMenu_string_14
};

const char uknCmd[] ="Unknown Command!";


#define  commandsCount 6
#define  commandlength 16
#define  subcommands 4
#define  intcomdTotalLenth commandlength * (subcommands +1)
const char commands[commandsCount][subcommands][commandlength] =
    {
        {"sensor","list","add","del"},
        {"alarmnumber","list","add","del"},
        {"changeip","na","",""},
        {"reboot","na","",""},
        {"debug","na","",""},
        {"help","na","",""}
    };

class SerialConsole
{

  public:

    SerialConsole(HardwareSerial& serial);
    HardwareSerial&  _Serial;
    SensorHandler& _SH;
    void refresh();
    void begin(int baud, SensorHandler& sensHand);
    private:
        void getCommand(int pos);
        int getCommandindex();
        int getSubCommandindex(int cmdidx);
        void parseCommand();
        void mnuHelp();
    int _inMenu=0;
    char cmd[12];
    char commandBuf[60];


};





#endif
