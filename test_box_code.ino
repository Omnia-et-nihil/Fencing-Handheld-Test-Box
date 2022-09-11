#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

const unsigned char startGraphic [] PROGMEM = { //Bitmap for the initialization graphic.
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0xbf, 0xff, 0xfc, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x07, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0x03, 0xff, 0xfe, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf0, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xe1, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const int rightButton = 10; //Pin assignments for the navigation buttons: left, select, and right.
const int selButton = 11;
const int leftButton = 12;

const int aLine = A1; //Analog pin assignments for the cord lines. Will read the voltage on their respective sockets. 
const int bLine = A2;
const int cLine = A3;

const int aVoltage = 9; //Digital pin assignments for the cord lines. Used to enable/disable the constant current through the line via transistors. 
const int bVoltage = 8;
const int cVoltage = 7;


int leftButtonState;             //Variables used in the debounce code.
int lastLeftButtonState = HIGH;
int selButtonState;
int lastSelButtonState = HIGH;
int rightButtonState;
int lastRightButtonState = HIGH;  
bool leftTemp;
bool leftReturn;
bool selTemp;
bool selReturn;
bool rightTemp;
bool rightReturn;
unsigned long lastLeftDebounceTime = 0;
unsigned long lastSelDebounceTime = 0;
unsigned long lastRightDebounceTime = 0;  
unsigned long debounceDelay = 50;   

int aVals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Initialization of arrays of readings of the resistance, non-linearly scaled, to be more sensitive to lower measurements. 
int bVals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int cVals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

bool ab; //Initialization of variables used for the cross-connection test. 
bool bc;
bool ac;

const int homepage = 0; //Definition of page numbers. These are used to keep track of which menu page and associated functions should be run.  
const int cordpage = 1;
const int bladepage = 2;
const int crosspage = 3;
const int lamepage = 4;
const int settings = 5;
const int setTests = 6;
const int confirmSet = 7;
const int zeropage = 8;
const int calibrate = 9;

int page = homepage;
int testpage = cordpage;
int lastpage = cordpage;

bool cordOn = true; //State variables determining whether each page is enabled or disabled by default when the device is powered on.
bool bladeOn = true;
bool crossOn = true;
bool lameOn = true;
bool zeroOn = true;


bool graphOrText = false; //State variable determining whether the resistance values are gaphed, or text is shown corresponding to certain value ranges. 

int line = 0;      //Variables for the highlight function used in menu pages. "line" tracks which line is currently highlighted.
int lineShift = 0; //For pages with more than three lines, lineShift keeps track of the offset as the pages are navigated, so that the correct three lines are always displayed.

const char tests0[] = " Cord"; //Due to memory issues involoving how the display handles strings, some of the text needs to be stored in this way to prevent glitching. 
const char tests1[] = " Zero";
const char tests2[] = " Blade";
const char tests3[] = " Cross";
const char tests4[] = " Lame";
const char tests5[] = " Back";

const char *tests[]  = {tests0,tests1,tests2,tests3,tests4,tests5};
const char *settingsGraph[] = {" Tests"," Graph"," Set"," Home"};
const char *settingsText[] = {" Tests"," Text"," Set"," Home"};

const int testAddress = 0;    //EEPROM memory addresses used to store settings through power cycles.
const int graphAddress = 1;
const int cordAddress = 2;
const int bladeAddress = 3;
const int crossAddress = 4;
const int lameAddress = 5;
const int zeroAddress = 6;

float aVal; //Variables use in the measurement functions.
float bVal;
float cVal;

float ra0 = 0.0; //variables used in the zeroing function, where the values are subtracted from the final resistance calculation to account for cord resistance when measuring blade resistances. 
float rb0 = 0.0;
float rc0 = 0.0;

const float aCurrent = .076; //Constant currents produced by the sources. 
const float bCurrent = .148;
const float cCurrent = .084;

float sum; //Used in the measurement functions for averaging readings. 

const float maxVal = 25.0; //Setting a maximum resistance value. Anything higher than 25 will read as 25. 

const float inc = 0.26; // Value used in the parabolic scaling function for the resistance vs time graph. 

int aText = 2; //More memory tricks to stop the display from glitching. 
int bText = 2;
int cText = 2;
const char *texts[3] = {"Good","Iffy","Bad"};

bool readLeft() {                                          //Debouncing function that reads the left button.
  int leftReading = digitalRead(leftButton);
  if(leftReading == HIGH){
    lastLeftDebounceTime = millis();
    leftReturn = true;
  }
  if(millis() - lastLeftDebounceTime > debounceDelay){
    if(leftReturn){
      leftTemp = true;
      leftReturn = false;
    }else{
      leftTemp = false;
    }
  }else{
    leftTemp = false;
  }
  lastLeftButtonState = leftReading;
  return leftTemp;
}

bool readSel() {                                           //Debouncing function that reads the center button.
  int leftReading = digitalRead(leftButton);
  int selReading = digitalRead(selButton);
  if(selReading == HIGH){
    lastSelDebounceTime = millis();
    selReturn = true;
  }
  if(millis() - lastSelDebounceTime > debounceDelay){
    if(selReturn){
      selTemp = true;
      selReturn = false;
    }else{
      selTemp = false;
    }
  }else{
    selTemp = false;
  }
  lastSelButtonState = selReading;
  return selTemp;
}

bool readRight() {                                         //Debouncing function that reads the right button.
  int leftReading = digitalRead(leftButton);
  int rightReading = digitalRead(rightButton);
  if(rightReading == HIGH){
    lastRightDebounceTime = millis();
    rightReturn = true;
  }
  if(millis() - lastRightDebounceTime > debounceDelay){
    if(rightReturn){
      rightTemp = true;
      rightReturn = false;
    }else{
      rightTemp = false;
    }
  }else{
    rightTemp = false;
  }
  lastRightButtonState = rightReading;
  return rightTemp;
}

void highlight(){                                          //Inverts the display for a given line of text.
  if(line != 0){
    for(int y = 16 * line; y < 16 * line + 14; y++){
      display.drawLine(0,y,127,y,2);
    }
  }
}


void initializeHomepage(){                                 //Initialization function for the homepage. 
  display.clearDisplay();                                  //Starts by clearing the display,then setting the cursor position and text color. 
  display.setCursor(0,0);
  display.setTextColor(1);
  display.println(" Home");                                //Begins writing text from the cursor's position(top right corner of the screen)
  display.println(" Test");
  display.println(" Settings");
  display.display();                                       //No changes made to what is shown on the display will take effect until this is called.
  line = 0;                                                //The "line" variable controls which line(other than 0) will be inverted with the highlight function. 
  lastpage = homepage;                                     //The "lastpage" variable, and setting it to "homepage" here, are used to ensure that this function is only called when switching to the homepage.
}

void Homepage(){               //This function will be run over and over as long as the current page is the homepage.
  if(lastpage != homepage){    //Ensuring the the initialization function only runs when the page has been changed to homepage from something else.
    initializeHomepage();
  }
  while(page == homepage){                                 
    if(readRight()){          //Checking to see if the right button has been pressed. 
      highlight();            //If so, the currently highlighted line is inverted back to normal. 
      line++;                 //The "line" value is increased by 1.
      if(line == 3){          //The homepage only has two lines, so 3 is cycled back to 1(line 0 is for the page name, so there is no need to select and highlight it).
        line = 1;
      }
      highlight();            //The newly selected line is now highlighted. 
      display.display();      //And displayed. 
    }
    if(readLeft()){           //This does the same thing as readRight, just decreasing line instead of increasing it.
      highlight();
      line--;
      if(line < 1){
        line = 2;
      }
      highlight();
      display.display();
    }
    if(readSel()){            //If the select button is pressed, the page is changed to whichever one corresponds to the text on that line.
      if(line == 1){
        page = testpage;     //"testpage" is not a constant value. It is set to one of the test page values, thus keeping track of the last test page, which will be the first one loaded from the homepage.
      }
      if(line == 2){
        page = settings;     //The other page that can be acessed directly from the homepage is the settings. 
      }
    }
  }
}

String GraphOrText(){    //Used in the settings to show whether the resistance graph or text will be displayed.
  if(graphOrText){
    return " Graph";
  }else{
    return " Text";
  }
}



void printSettings(){ //The settings page has more than three lines of options, so this function prints the correct three based on which line is selected, as well as the current offset from "lineShift"
  display.clearDisplay();
  display.setTextColor(1);
  display.setCursor(0,0);
  display.println(" Settings");
  if(graphOrText){
    for(int i = 0; i < 3; i++){
      display.println(settingsGraph[i + lineShift]);
    }
  }else{
    for(int i = 0; i < 3; i++){
      display.println(settingsText[i + lineShift]);
    }
  }
}

void initializeSettings(){ //Initialization function for the settings page. 
  line = 0;
  lineShift = 0;
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextColor(1);
  printSettings();
  display.display();
  lastpage = settings;
}

void Settings(){   //Settings page function.
  if(lastpage != settings){ 
    initializeSettings();
  }
  while(page == settings){
    if(readRight()){           //Using the lineshift to scroll the highlight and the three displayed lines.
      highlight();
      if(line == 3){
        if(lineShift < 1){
          lineShift++; 
          printSettings();
          highlight();
          display.display();
        }else{
          lineShift = 0;
          line = 1;
          printSettings();
          highlight();
          display.display();
          }
      }else{
        line++;
        highlight();
        display.display();
      }
    }
    if(readLeft()){
    highlight();
    if(line < 2){
      if(lineShift > 0){
        lineShift--;
        printSettings();
        highlight();
        display.display();
      }else{
        lineShift = 1;
        line = 3;
        printSettings();
        highlight();
        display.display();
      }
    }else{
      line--;
      highlight();
      display.display();
    }
   }
    
    if(readSel()){
      switch(line + lineShift){
        case 0:
        page = homepage;          //Back to the homepage Line zero is where the highlight starts when a page is first opened, but doesn't actually highlight anything and can't be scrolled back to.
        break;
      
        case 1:
        page = setTests;          //To the setTests page
        break;

        case 2:
        graphOrText = !graphOrText; //Toggles the state of the graphOrText boolean and then refreshes the display to display the changed state.
        printSettings();
        highlight();
        display.display();
        break;

        case 3:
        page = confirmSet;          //To the confirmSet page
        break;

        case 4:
        page = homepage; //Another back to homepage. Since line zero cannot be scrolled back to this line is added to provide an additional back to home. This is done for aesthetic preferences for the UI. 
        break;
      }
    }
  }
}

void Set(){ //Stores the current settings in EEPROM memory.
  EEPROM.update(testAddress,testpage);
  EEPROM.update(graphAddress,graphOrText);
  EEPROM.update(cordAddress,cordOn);
  EEPROM.update(bladeAddress,bladeOn);
  EEPROM.update(crossAddress,crossOn);
  EEPROM.update(lameAddress,lameOn);
  EEPROM.update(zeroAddress,zeroOn);
}

void initializeConfirmSet(){ //Initialization for the confirm set page.
  display.clearDisplay();
  display.setTextColor(1);
  display.setCursor(0,0);
  display.println(" Confirm");
  display.println(" Yes");
  display.println(" No");
  display.display();
  lastpage = confirmSet;
  line = 0;
}

void ConfirmSet(){
  if(lastpage != confirmSet){
    initializeConfirmSet();
  }
  while(page == confirmSet){ //Navigation between the two lines: "Yes" and "No"
    if(readRight()){
      highlight();
      line++;
      if(line > 2){
        line = 1;
      }
      highlight();
      display.display();
    }
    if(readLeft()){
      highlight();
      line--;
      if(line < 1){
        line = 2;
      }
      highlight();
      display.display();
    }
    if(readSel()){  //When the select button is pressed it returns to the homepage if "No" or line 0 was selected. If "Yes" was selected the settings are stored in EEPROM before returning to the homepage. 
      if(line == 1){
        Set();
      }
      page = homepage;
    }
  }
}

void printTestTicks(){  //This is used in the setTests page to show which of the testing pages are enabled/disabled. 
  if(lineShift == 0){
    display.drawChar(74,16,0x04,cordOn,0,2);
    display.drawChar(74,32,0x04,zeroOn,0,2);
    display.drawChar(74,48,0x04,bladeOn,0,2);
  }
  if(lineShift == 1){
    display.drawChar(74,16,0x04,zeroOn,0,2);
    display.drawChar(74,32,0x04,bladeOn,0,2);
    display.drawChar(74,48,0x04,crossOn,0,2);
  }
  if(lineShift == 2){
    display.drawChar(74,16,0x04,bladeOn,0,2);
    display.drawChar(74,32,0x04,crossOn,0,2);
    display.drawChar(74,48,0x04,lameOn,0,2);
  }
  if(lineShift == 3){
    display.drawChar(74,16,0x04,crossOn,0,2);
    display.drawChar(74,32,0x04,lameOn,0,2);
  }
}

void printTestLines(){  //Prints the appropriate lines of text based on the lineShift offset.
  display.clearDisplay();
  display.setTextColor(1);
  display.setCursor(0,0);
  display.println(" Set Tests");
  display.println(tests[0 + lineShift]);
  display.println(tests[1 + lineShift]);
  display.println(tests[2 + lineShift]);
}

void initializeSetTests(){ //Initialization.
  line = 0;
  lineShift = 0;
  printTestLines();
  printTestTicks();
  display.display();
  line = 0;
  lastpage = setTests;
}

void SetTests(){ //SetTests page. Creates a navigable list of tests which can be individually enabled/disabled by pressing select while highlighted. 
  if(lastpage != setTests){
    initializeSetTests();
  }
  while(page == setTests){
    if(readRight()){
      if(line < 3){  //If the highlighted line is below three, than it may be incremented without adjusting the displlayed lines.
        highlight();
        line++;
        highlight();
        display.display();
      }else{       //If the highlighted line is three than instead, the displayed lines must be adjusted, done by increasing the lineShift.
        if(lineShift < 3){
          lineShift++;
          printTestLines();
          printTestTicks();
          highlight();
          display.display();
        }else{ //Scrolling past the end of the list cycles back to the beginning.
          lineShift = 0;
          line = 1;
          printTestLines();
          printTestTicks();
          highlight();
          display.display();
        }
      }
    }
    if(readLeft()){ //Same the right, but scrolls in the opposite direction.
      if(line > 1){
        highlight();
        line--;
        highlight();
        display.display();
      }else{
        if(lineShift > 0){
        lineShift--;
        printTestLines();
        printTestTicks();
        highlight();
        display.display();
        }else{
          lineShift = 3;
          line = 3;
          printTestLines();
          printTestTicks();
          highlight();
          display.display();
        }
      }
    }
    if(readSel()){  //Toggles the state of the enable/disable bool for each test page, returns to home, or goes back to settings. 
      switch(line + lineShift){
        case 0:
        page = homepage;
        break;
        
        case 1:
        cordOn = !cordOn;
        break;

        case 2:
        zeroOn = !zeroOn;
        break;

        case 3:
        bladeOn = !bladeOn;
        break;

        case 4:
        crossOn = !crossOn;
        break;

        case 5:
        lameOn = !lameOn;
        break;

        case 6:
        switch(testpage){ //This part isn't strictly necessary, but is done for UI smoothness. It ensures that if you have disabled the current testpage, that another will be automatically selected.
          case cordpage:
          if(cordOn){
            break;
          }
          if(zeroOn){
            testpage = zeropage;
          }
          if(bladeOn){
            testpage = bladepage;
            break;
          }else if(crossOn){
            testpage = crosspage;
            break;
          }else if(lameOn){
            testpage = lamepage;
            break;
          }else{
            testpage = cordpage;
            break;
          }

          case zeropage:
          if(zeroOn){
            break;
          }else if(bladeOn){
            testpage = bladepage;
            break;
          }else if(crossOn){
            testpage = crosspage;
            break;
          }else if(lameOn){
            testpage = lamepage;
            break;
          }else{
            testpage = cordpage;
            break;
          }

          case bladepage:
          if(bladeOn){
            break;
          }else if(crossOn){
            testpage = crosspage;
            break;
          }else if(lameOn){
            testpage = lamepage;
            break;
          }else if(cordOn){
            testpage = cordpage;
            break;
           }else if(zeroOn){
            testpage = zeropage;
            break;
           }else{
            testpage = cordpage;
            break;
           }

          case crosspage:
          if(crossOn){
            break;
          }else if(lameOn){
            testpage = lamepage;
            break;
          }else if(cordOn){
            testpage = cordpage;
            break;
          }else if(zeroOn){
            testpage = zeropage;
            break;
          }else if(bladeOn){ 
            testpage = bladepage;
            break;
          }else{
             testpage = cordpage;
             break;
          }

          case lamepage:
          if(lameOn){
            break;
          }else if(cordOn){
            testpage = cordpage;
            break;
          }else if(zeroOn){
            testpage = zeropage;
            break;
          }else if(bladeOn){
            testpage = bladepage;
            break;
          }else if(crossOn){
            testpage = crosspage;
            break;
          }else{
            testpage = cordpage;
            break;
          }
        }
        page = settings; //And concludes by returning to settings.
        break;
      }
      highlight();       //Whenever the status of a test page is changed, the ticks are updated to reflect it.
      printTestTicks();
      highlight();
      display.display();
    }
  }
}

void getResistanceA(){ //Function to read the resistance on the A line.
  sum = 0.;
  for(int i = 0; i < 3; i++){ //Averages over three readings.
    sum += (5.*analogRead(aLine)/1024.)/aCurrent;
  }
  aVal = 1.000*sum/3.;
  if(page == bladepage || page == lamepage){
    aVal -= (ra0 + rb0);
  }
  if(page == zeropage || page == cordpage){
    aVal -= ra0;
  }
  if(aVal > maxVal){
    aVal = maxVal;
  }
}

void getResistanceB(){ //Almost the same function as for A.
  sum = 0.;
  for(int i = 0; i < 3; i++){
    sum += (5.*analogRead(bLine)/1024.)/bCurrent;
  }
  bVal = 1.111*sum/3.;
  if(page == zeropage || page == cordpage){ //A-B resistance is measured by blade test, and the B resistance is already factored into the "A" reading on that page. 
    bVal -= rb0;
  }
  if(bVal > maxVal){
    bVal = maxVal;
  }
}

void getResistanceC(){ //Similar for C.
  sum = 0.;
  for(int i = 0; i < 3; i++){
    sum  += (5.*analogRead(cLine)/1024.)/cCurrent;
  }
  cVal = 0.758*sum/3.;
  if(page == bladepage){ //B-C resistance is also measured in the blade test. 
    cVal -= (rb0 + rc0);
  }
  if(page == zeropage || page == cordpage){
    cVal -= rc0;
  }
  if(cVal > maxVal){
    cVal = maxVal;
  }
}

int getNewVal(float val){ //Scaling function to adjust the resistance values for graphing. 
 for(int i = 0; i < 13; i++){
  if(val < ((i + 1)*(0.1) + (i*(i+1)/2.)*inc)){
    return i;
  }
 }
 return 13;
}    

void updateAVals(){ //The graphing values are stored in an array. When a new value is measured, it is scaled, each value in the array is moved up one and the new value added to the beginning.
  for(int i = 0; i < 23; i++){
    aVals[i] = aVals[i + 1]; 
  }
  aVals[23] = getNewVal(aVal);
}

void updateBVals(){ //Same as for the A vals. 
  for(int i = 0; i < 23; i++){
    bVals[i] = bVals[i + 1];
  }
  bVals[23] = getNewVal(bVal);
}

void updateCVals(){ //Same as for the C vals.
  for(int i = 0; i < 23; i++){
    cVals[i] = cVals[i + 1];
  }
  cVals[23] = getNewVal(cVal);
}

void drawA(){ //Plots the A values at the end of the A line.
  for(int i = 0; i < 24; i++){
    display.drawPixel(104 + i, 30 - aVals[i], 2);
  }
}

void drawB(){ //Plots the B values at the end of the B line.
  for(int i = 0; i < 24; i++){
    display.drawPixel(104 + i, 46 - bVals[i], 2);
  }
}

void drawC(){ //Plots the C values at the end of the C line.
  for(int i = 0; i < 24; i++){
    display.drawPixel(104 + i, 62 - cVals[i], 2);
  }
}

void textResistanceA(){ //Plots the A resistance text: "Good", "Iffy", or "Bad"
  display.setCursor(74,16);
  display.print(texts[aText]);
}

void textResistanceB(){ //Plots the B resistance text.
  display.setCursor(74,32);
  display.print(texts[bText]);
}

void textResistanceC(){ //Plots the C resistance text.
  display.setCursor(74,48);
  display.print(texts[cText]);
}

void updateAText(){ //Updates the A resistance text.
  if(aVal < 2.0){
    aText = 0;
  }else if(aVal < 10.0){
    aText = 1;
  }else{
    aText = 2;
  }
}

void updateBText(){ //Updates the B resistance text.
  if(bVal < 2.0){
    bText = 0;
  }else if(bVal < 10.0){
    bText = 1;
  }else{
    bText = 2;
  }
}

void updateCText(){ //Updates the C resistance text.
  if(cVal < 2.0){
    cText = 0;
  }else if(cVal < 10.0){
    cText = 1;
  }else{
    cText = 2;
  }
}

void testCord(){ //The cord resistance test function.
  display.setCursor(18,16); //Prints the A, B, and C resistance values to 1 decimal point. Since the initialization function sets the color to 2(invert) this essentially clears the printed value.
  display.print(aVal,1);
  display.setCursor(18,32);
  display.print(bVal,1);
  display.setCursor(18,48);
  display.print(cVal,1);
                     
  digitalWrite(aVoltage,HIGH); //Due to technical limitations, measurements should be taken one at a time to prevent interference. 
  digitalWrite(bVoltage,LOW);
  digitalWrite(cVoltage,LOW);
  pinMode(aLine,INPUT);
  pinMode(bLine,OUTPUT);
  pinMode(cLine,OUTPUT);
  digitalWrite(bLine,LOW);
  digitalWrite(cLine,LOW);
  delay(5); //Slight delay to allow transient effects to pass before measurements are taken. 
  if(graphOrText){ //Plots the resistance graph or displays the resistance text depending on the state of the relevant bool.
    drawA();
  }else{
    textResistanceA();
  }
  getResistanceA(); //Measures the new A resistance and updates either the graph or text. 
  if(graphOrText){
    updateAVals();
    drawA();
  }else{
    updateAText();
    textResistanceA();
  }

  digitalWrite(aVoltage,LOW); //The procedure is repeated with the pins changed to those for measuring B.
  digitalWrite(bVoltage,HIGH);
  digitalWrite(cVoltage,LOW);
  pinMode(bLine,INPUT);
  pinMode(aLine,OUTPUT);
  pinMode(cLine,OUTPUT);
  digitalWrite(aLine,LOW);
  digitalWrite(cLine,LOW);
  delay(5);
  if(graphOrText){
    drawB();
  }else{
    textResistanceB();
  }
  getResistanceB();
  if(graphOrText){
    updateBVals();
    drawB();
  }else{
    updateBText();
    textResistanceB();
  }

  digitalWrite(aVoltage,LOW); //Same thing again for C.
  digitalWrite(bVoltage,LOW);
  digitalWrite(cVoltage,HIGH);
  pinMode(cLine,INPUT);
  pinMode(bLine,OUTPUT);
  pinMode(aLine,OUTPUT);
  digitalWrite(bLine,LOW);
  digitalWrite(aLine,LOW);
  delay(5);
  if(graphOrText){
    drawC();
  }else{
    textResistanceC();
  }
  getResistanceC();
  if(graphOrText){
    updateCVals();
    drawC();
  }else{
    updateCText();
    textResistanceC();
  }
  
  display.setCursor(18,16); //Finally the updated resistance values are printed on the display. 
  display.print(aVal,1);
  display.setCursor(18,32);
  display.print(bVal,1);
  display.setCursor(18,48);
  display.print(cVal,1);
    
  display.display(); //The display is now refreshed with the updated text/graphs and values. 
}
  
void initializeCordpage(){ //Initialization function for the cord test page.
  display.clearDisplay();
  display.setTextColor(2); //Sets the color to to invert, meaning that printing something again will clear that part of the screen, enabling individual elements to be changed without clearing everything.
  display.setCursor(0,0);
  display.println("Cord Test"); 
  display.println("A");
  display.println("B");
  display.println("C");
  display.setCursor(18,16);
  display.print(aVal,1);
  display.setCursor(18,32);
  display.print(bVal,1);
  display.setCursor(18,48);
  display.print(cVal,1);

  if(graphOrText){
    drawA();
    drawB();
    drawC();
  }else{
    textResistanceA();
    textResistanceB();
    textResistanceC();
  }

  
  display.display();
  lastpage = cordpage;
  testpage = cordpage;
  pinMode(aLine,INPUT);
  pinMode(bLine,INPUT);
  pinMode(cLine,INPUT);
  digitalWrite(aVoltage,LOW);
  digitalWrite(bVoltage,LOW);
  digitalWrite(cVoltage,LOW);
}

void Cordpage(){ //Cord test page function.
  if(lastpage != cordpage){
    initializeCordpage();
  }
  while(page == cordpage){
    testCord();
    if(readRight()){ //Scrolls through pages depending on which are enablled/disabled.
      if(zeroOn){
        page = zeropage;
      }else if(bladeOn){
        page = bladepage;
      }else if(crossOn){
        page = crosspage;
      }else if(lameOn){
        page = lamepage;
      }else{
        page = cordpage;
      }
    }
    if(readLeft()){
      if(lameOn){
        page = lamepage;
      }else if(crossOn){
        page = crosspage;
      }else if(bladeOn){
        page = bladepage;
      }else if(zeroOn){
        page = zeropage;
      }else{
        page = cordpage;
      }
    }
    if(readSel()){
      page = homepage;
    }
  }
}

void initializeZeroPage(){ //Initialization function for the zero cord page. It is essentially the same as for the test cord initialization. 
  display.clearDisplay();
  display.setTextColor(2);
  display.setCursor(0,0);
  display.println("Zero Cord");
  display.println("A");
  display.println("B");
  display.println("C");
  display.setCursor(18,16);
  display.print(aVal,1);
  display.setCursor(18,32);
  display.print(bVal,1);
  display.setCursor(18,48);
  display.print(cVal,1);

  if(graphOrText){
    drawA();
    drawB();
    drawC();
  }else{
    textResistanceA();
    textResistanceB();
    textResistanceC();
  }

  display.display();
  lastpage = zero;
  testpage = zero;
  pinMode(aLine,INPUT);
  pinMode(bLine,INPUT);
  pinMode(cLine,INPUT);
  digitalWrite(aVoltage,LOW);
  digitalWrite(bVoltage,LOW);
  digitalWrite(cVoltage,LOW);
  
}  

void zero(){ //This is functionally about the same as the cord test, the only difference occuring when the selct button is pressed, instead of returning to home, the resistance values are stored. 
  if(lastpage != zeropage){
    initializeZeroPage();
  }
  while(page == zeropage){
    testCord();
    if(readRight()){
      if(bladeOn){
        page = bladepage;
      }else if(crossOn){
        page = crosspage;
      }else if(lameOn){
        page = lamepage;
      }else if(cordOn){
        page = cordpage;
      }else{
        page = zeropage;
      }
    }
    if(readLeft()){
      if(cordOn){
        page = cordpage;
      }else if(lameOn){
        page = lamepage;
      }else if(crossOn){
        page = crosspage;
      }else if(bladeOn){
        page = bladepage;
      }else{
        page = zeropage;
      }
    }
    if(readSel()){
      if(aVal +ra0 >= maxVal){
        ra0 = 0.0;
      }else{
        ra0 = aVal;
      }
      if(bVal + rb0 >= maxVal){
      rb0 = 0.0;
      }else{
      rb0 = bVal;
      }
      if(cVal + rc0 >= maxVal){
        rc0 = 0.0;
      }else{
      rc0 = cVal;
      }
      display.invertDisplay(true);
      display.display();
      delay(350);
      display.invertDisplay(false);
    }
    
  }

}

void testBlade(){ //Testing function. Functionally equivalent to the cord test, but without the B line being measured.
  display.setCursor(18,16);
  display.println(aVal,1);
  display.setCursor(18,48);
  display.println(cVal,1);
  
  digitalWrite(aVoltage,HIGH);
  pinMode(aLine,INPUT);
  pinMode(cLine,OUTPUT);
  digitalWrite(cLine,LOW);
  delay(5);
  if(graphOrText){
    drawA();
  }else{
    textResistanceA();
  }
  getResistanceA();
  if(graphOrText){
    updateAVals();
    drawA();
  }else{
    updateAText();
    textResistanceA();
  }
  
  digitalWrite(aVoltage,LOW);
  digitalWrite(cVoltage,HIGH);
  pinMode(cLine,INPUT);
  pinMode(aLine,OUTPUT);
  digitalWrite(aLine,LOW);
  delay(5);
  if(graphOrText){
    drawC();
  }else{
    textResistanceC();
  }
  getResistanceC();
  if(graphOrText){
    updateCVals();
    drawC();
  }else{
    updateCText();
    textResistanceC();
  }
  digitalWrite(cVoltage,LOW);
  display.setCursor(18,16);
  display.println(aVal,1);
  display.setCursor(18,48);
  display.println(cVal,1);
  display.display();
}

void initializeBladepage(){ //Initializes the blade test page. "A" will display the A-B resistance and "C" will display the B-C resistance. There is no need for the "B" line.
  display.clearDisplay();
  display.setTextColor(2);
  display.setCursor(0,0);
  display.println("Blade Test");
  display.println("A");
  display.println("");
  display.println("C");
  display.setCursor(18,16);
  display.println(aVal,1);
  display.setCursor(18,48);
  display.println(cVal,1);

  if(graphOrText){
    drawA();
    drawC();
  }else{
    textResistanceA();
    textResistanceC();
  }
  
  display.display();
  lastpage = bladepage;
  testpage = bladepage;
  digitalWrite(aVoltage,LOW);
  digitalWrite(bVoltage,LOW);
  digitalWrite(cVoltage,LOW);
  pinMode(bLine,OUTPUT);
  digitalWrite(bLine,LOW);
}

void Bladepage(){ //Blade test page.
  if(lastpage != bladepage){
    initializeBladepage();
  }
  while(page == bladepage){
    testBlade();
    if(readRight()){
      if(crossOn){
        page = crosspage;
      }else if(lameOn){
        page = lamepage;
      }else if(cordOn){
        page = cordpage;
      }else if(zeroOn){
        page = zeropage;
      }else{
        page = bladepage;
      }
    }
    if(readLeft()){
      if(zeroOn){
        page = zeropage;
      }else if(cordOn){
        page = cordpage;
      }else if(lameOn){
        page = lamepage;
      }else if(crossOn){
        page = crosspage;
      }else{
        page = bladepage;
      }
    }
    if(readSel()){
      page = homepage;
    }
  }
}

void crossTest(){ //This tests(without measuring resistances) if there are any cross-connections in the bodycord.
  pinMode(cLine,INPUT_PULLUP); //The initialization function also sets aLine as an input pullup and disables aVoltage, bVoltage, and cVoltage.
  delay(1); //Waiting for the transient effects to stabalize is less important here since precise measurements are not required. 
  ab = !digitalRead(aLine); //If aLine is at zero, this means there is a cross-connection between the A and B lines of the cord.
  bc = !digitalRead(cLine); //Same as above, but with  C instead of A.
  if(ab && bc){ //If a cross-connection is detected on AB and BC, then AC must therefore be conneted too. 
    ac = true;
  }else{ //If one only of AB and BC have cross connections, there necessarily cannot be a three-way conection, so AC cannot be cross-connected.
    ac = false;
  }
  if(!ab && !bc){ //But what if neither AB nor BC are cross-conneted?
    pinMode(cLine,OUTPUT); //Now cLine is set to a low output, serving as a ground. 
    digitalWrite(cLine,LOW);
    delay(1);
    ac = !digitalRead(aLine); //If this reads low, it means that there is a cross-connection with either B or C. Since this is only done if there is no AB connection, there must be an AC connction.
  }
  display.drawChar(40,16,0x2A,ab,0,2); //Displays a character next to each of the Ab,BC, and AC lines with color set to the state bool. 
  display.drawChar(40,32,0x2A,bc,0,2);
  display.drawChar(40,48,0x2A,ac,0,2);
  display.display();

}

void initializeCrosspage(){ //Initializes crosspage. 
  display.clearDisplay();
  display.setTextColor(1);
  display.setCursor(0,0);
  display.println("Cross Test");
  display.println("A-B");
  display.println("B-C");
  display.println("A-C");
  display.display();
  lastpage = crosspage;
  testpage = crosspage;
  digitalWrite(aVoltage,LOW); //All the voltage lines are set low, as the constant current is not used in this test. 
  digitalWrite(bVoltage,LOW);
  digitalWrite(cVoltage,LOW);
  pinMode(aLine,INPUT_PULLUP); //The A line will always be an input pullup, so that is done here so as not to add reundancy to the test function.
  pinMode(bLine,OUTPUT);
}

void Crosspage(){ //Same as the other test pages. 
  if(lastpage != crosspage){
    initializeCrosspage();
  }
  while(page == crosspage){
    crossTest();
    if(readRight()){
      if(lameOn){
        page = lamepage;
      }else if(cordOn){
        page = cordpage;
      }else if(zeroOn){
        page = zeropage;
      }else if(bladeOn){
        page = bladepage;
      }else{
        page = crosspage;
      }
    }
    if(readLeft()){
      if(bladeOn){
        page = bladepage;
      }else if(zeroOn){
        page = zeropage;
      }else if(cordOn){
        page = cordpage;
      }else if(lameOn){
        page = lamepage;
      }else{
        page = crosspage;
      }
    }
    if(readSel()){
      page = homepage;
    }
  }
}

void testLame(){  //Lame test. Since this only uses the A line, it can be left on continuously instead of toggled like in the other tests. 
  if(graphOrText){
    drawA();
  }else{
    textResistanceA();
  }
  display.setCursor(18,16);
  display.println(aVal,1);
  getResistanceA();
  if(graphOrText){
    updateAVals();
    drawA();
  }else{
    updateAText();
    textResistanceA();
  }
  display.setCursor(18,16);
  display.println(aVal,1);
  display.display();
}

void initializeLamepage(){ //Nothing new here.
  display.clearDisplay();
  display.setTextColor(2);
  display.setCursor(0,0);
  display.println("Lame Test");
  display.println("A");
  display.setCursor(18,16);
  display.println(aVal,1);
  if(graphOrText){
    drawA();
  }else{
    textResistanceA();
  }
  display.display();
  lastpage = lamepage;
  testpage = lamepage;
  digitalWrite(aVoltage,HIGH);
  digitalWrite(bVoltage,LOW);
  digitalWrite(cVoltage,LOW);
  pinMode(aLine,INPUT);
  pinMode(bLine,OUTPUT);
  pinMode(cLine,OUTPUT);
  digitalWrite(bLine,LOW);
  digitalWrite(cLine,LOW);
}

void Lamepage(){ //Or here.
  if(lastpage != lamepage){
    initializeLamepage();
  }
  while(page == lamepage){
    testLame();
    if(readRight()){
      if(cordOn){
        page = cordpage;
      }else if(zeroOn){
        page = zeropage;
      }else if(bladeOn){
        page = bladepage;
      }else if(crossOn){
        page = crosspage;
      }else{
        page = lamepage;
      }
    }
    if(readLeft()){
      if(crossOn){
        page = crosspage;
      }else if(bladeOn){
        page = bladepage;
      }else if(zeroOn){
        page = zeropage;
      }else if(cordOn){
        page = cordpage;
      }else{
        page = lamepage;
      }
    }
    if(readSel()){
      page = homepage;
    }
  }
}

void setup(){ //Setup function when the box is first powered on.
  testpage = EEPROM.read(testAddress); //Initializes settings from EEPROM storage. 
  graphOrText = EEPROM.read(graphAddress);
  cordOn = EEPROM.read(cordAddress);
  bladeOn = EEPROM.read(bladeAddress);
  crossOn = EEPROM.read(crossAddress);
  lameOn = EEPROM.read(lameAddress);
  zeroOn = EEPROM.read(zeroAddress);
  pinMode(leftButton,INPUT_PULLUP); //The button pins should be input pullups. 
  pinMode(selButton,INPUT_PULLUP);
  pinMode(rightButton,INPUT_PULLUP);
  pinMode(aVoltage,OUTPUT); //The voltage pins should be outputs(these serve as digital switches that turn on/off the constant current sources).
  pinMode(bVoltage,OUTPUT);
  pinMode(cVoltage,OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Initializing the display.
  display.clearDisplay();
  display.setTextColor(1);
  display.setTextSize(2);
  display.drawBitmap(8,5,startGraphic,122,59,WHITE);
  display.display();
  delay(500); //It isn't strictly necessary to display the start graphic like this, or even at all; the choice was made for aesthetic reasons. 
}

void loop(){ //checks what the current page is and runs the apropriate function, which will therefore run every iteration of the loop until the page is changed. 
  switch(page){
    case homepage:
    Homepage();
    break;

    case settings:
    Settings();
    break;

    case setTests:
    SetTests();
    break;

    case confirmSet:
    ConfirmSet();
    break;

    case cordpage:
    Cordpage();
    break;

    case zeropage:
    zero();
    break;

    case bladepage:
    Bladepage();
    break;

    case crosspage:
    Crosspage();
    break;

    case lamepage:
    Lamepage();
    break;
  }
}
