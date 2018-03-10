#include <SerialConsole.h>
#include <SensorHandler.h>


SerialConsole::SerialConsole(HardwareSerial& serial): _Serial(serial){



}
void SerialConsole::begin(int baud,SensorHandler& sensHand){
    _Serial.begin(baud);
    _Serial.print("init");
    _SH = sensHand;
}


void SerialConsole::getCommand(int pos){
  int commacount=0;
  int idx=0;
  memset(cmd, 0, sizeof(cmd));
  for (int i =0; i< sizeof(commandBuf)-1;i++){
      if (commandBuf[i]=='\0'){break;};
      if (commandBuf[i]==' '){
          if (commacount=pos){
              break;
          }else {
               memset(cmd, 0, sizeof(cmd));
          }
        commacount++;
        idx=0;
      } else {
            cmd[idx]= commandBuf[i];
        }
        idx++;
      }
  }

void SerialConsole::refresh(){
    int idx=0;
    memset(commandBuf, 0, sizeof(commandBuf));
      while (Serial.available() > 0) {
                commandBuf[idx]=_Serial.read();
                if (commandBuf[idx]=='\n') {break;};
      }
if (sizeof(commandBuf) > 1){
parseCommand();
}

}
int  SerialConsole::getCommandindex(){
bool Found=false;
    for(int i =0;i<commandsCount;i++){
        if (cmd==commands[i][0]){
            Found=true;
            return i;
        }
    }
if(!Found){return -1;};
}

int  SerialConsole::getSubCommandindex(int cmdidx){
bool Found=false;
    for(int i =1;i<subcommands;i++){
        if (cmd==commands[cmdidx][i]){
            Found=true;
            return i;
        }
    }
if(!Found){return -1;};
}

void SerialConsole::parseCommand(){
getCommand(0);
int cmdidx=getCommandindex();
    if(cmdidx>-1){

    } else {
        _Serial.println(uknCmd);
    }
}

void SerialConsole::mnuHelp(){



}
