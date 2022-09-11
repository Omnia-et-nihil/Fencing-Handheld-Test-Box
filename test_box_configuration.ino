#include <EEPROM.h>

const int cordpage = 1; //Defining the variables to be set. Technically they don't need to be laid out here, but this format makes it easier to make and follow changes if desired.
const int bladepage = 2;
const int crosspage = 3;
const int lamepage = 4;

const int testAddress = 0;
const int graphAddress = 1;
const int cordAddress = 2;
const int bladeAddress = 3;
const int crossAddress = 4;
const int lameAddress = 5;
const int zeroAddress = 6;

//Different functions are defined to set different presets.

void configureA(){ //Sets the default test page to cord, enables all test pages, and enables the graph vs text.
  EEPROM.update(testAddress, cordpage);
  EEPROM.update(graphAddress, true);
  EEPROM.update(cordAddress, true);
  EEPROM.update(bladeAddress, true);
  EEPROM.update(crossAddress, true);
  EEPROM.update(lameAddress, true);
  EEPROM.update(zeroAddress, true);
}

void configureB(){ //Sets the default test page to cord, enables all test pages except zero, and enables the text vs graph.
  EEPROM.update(testAddress, cordpage);
  EEPROM.update(graphAddress, false);
  EEPROM.update(cordAddress, true);
  EEPROM.update(bladeAddress, true);
  EEPROM.update(crossAddress, true);
  EEPROM.update(lameAddress, true);
  EEPROM.update(zeroAddress, false);
}

void setup(){
  Serial.begin(9600);
  configureA(); //Sets to the desired preset. 
  Serial.print("Test: "); //Prints the EEPROM values to confirm successful configuration.
  Serial.println(EEPROM.read(testAddress));
  Serial.print("Graph: ");
  Serial.println(EEPROM.read(graphAddress));
  Serial.print("Cord: ");
  Serial.println(EEPROM.read(cordAddress));
  Serial.print("Blade: ");
  Serial.println(EEPROM.read(bladeAddress));
  Serial.print("Cross: ");
  Serial.println(EEPROM.read(crossAddress));;
  Serial.print("Lame: ");
  Serial.println(EEPROM.read(lameAddress));
  Serial.print("Set Blade: ");
  Serial.println(EEPROM.read(zeroAddress));
}

void loop(){
}
