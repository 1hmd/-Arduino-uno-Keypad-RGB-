#include "Keypad.h"
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
}; //array of the keypad
byte rowPins[ROWS] = {11, 2, 7, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 12, 8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //This creates a keymap (get colPins, ROWS, COLS)
char holdKey; // to check which key am i pressing
unsigned long t_hold; //this to check if your holding the key all way
bool spam = true; //Start with teh spam on
int holdNumber[10] = {0};
int R;  //color red
int G; //color green
int B; //color blue
void setup(){
  pinMode(3, OUTPUT); // G
  pinMode(5, OUTPUT); // B
  pinMode(6, OUTPUT); // R
  Serial.begin(9600); //used to initialize the serial communication port on an Arduino board
}
void shutdonwLights() { // Make the lighs go to shuts down after 0.5s
  delay(500);
  R = 255; G = 255;  B = 255;
  analogWrite(6, R); analogWrite(3, G); analogWrite(5, B);
}
bool charCheck(){
 char newkey = keypad.getKey(); //check witch key your are clicking before the loop starts again so you should spam this keypad to leave this mode
 if (newkey != 0) { // why the 0 is not in "", I don't know to be honst (as long it's working I will not change it because why not?)
  return true;
 }
 return false;
}
//* Lights RGB FUNCTIONS
void rgbLights1() {
  for (int i = 0; i < 255; i++) {
    delay(1);
    analogWrite(3, 255);
    analogWrite(5, i);
    delay(1);
    analogWrite(6, 255 - i);
  }
}
void rgbLights2() {
  for (int i = 0; i < 255; i++) {
    delay(1);
    analogWrite(3, 255 - i);
    delay(1);
    analogWrite(5, 255);
    analogWrite(6, i);
  }
}
void rgbLights3() {
  for (int i = 0; i < 255; i++) {
    delay(1);
    analogWrite(3, i);
    analogWrite(5, 255 - i);
    delay(1);
    analogWrite(6, 255);
  }
}
void loop(){
  char key = keypad.getKey(); //check the key you are clicking
  if(key == '#'){ //turn on/off spam mode
    spam = false;
    shutdonwLights();
  }else if(key == '*'){
    spam = true;
    shutdonwLights();
  }
  if (spam){
   if (key){ //to check if the key been hold
      holdKey = key;
    }
    if (!holdKey) { //to turn off the lights on start
      R = 255; G = 255;  B = 255;
      analogWrite(6, R); analogWrite(3, G); analogWrite(5, B);
    }
    if (keypad.getState() == HOLD) { //The spam effect
      if ((millis() - t_hold) > 100 ) { // cool function check if holding key all way down
        for (int i = 0; i < 10; i++) { //You can use switch here will work as same.
          if (holdKey == '0' + i) { //check witch key you are clicking
            holdNumber[i] = 1; //This is they key you are clicking?? make it one
          } else {
            holdNumber[i] = 0; //else? make it 0
          }
        }
        t_hold = millis(); // Store the current time in milliseconds (no i will not sell your data)
      }
    }else{
      for (int i = 0; i < 10; i++) {
        holdNumber[i] = 0;
      } //Make all the number to 0 if you are not holding any number.
    }
  }else{
    if(key!= NO_KEY){ //The normal effect
      switch (key) {
        case '1': R = 255; G = 0;   B = 0; break;
        case '2': R = 0;   G = 255; B = 0; break;
        case '3': R = 0;   G = 0;   B = 255; break;
        case '4': R = 255; G = 255; B = 0; break;
        case '5': R = 255; G = 0;   B = 255; break;
        case '6': R = 0;   G = 255; B = 255; break;
        case '7': R = 0;   G = 0;   B = 0; break;
        case '8': R = 55;  G = 155; B = 255; break;
        case '9': R = 138; G = 43;  B = 226; break;
        case '0':
        while (true) {
          if (charCheck()) { //this thing make the code leave the rgb mode
            break;
          }
          rgbLights1(); //* RGB ONE
          if (charCheck()) {
            break;
          }
          rgbLights2(); //* RGB TWO
          if (charCheck()) {
            break;
          }
          rgbLights3(); //* RGB three
        }
        break;
      }
      //This code reads input from a keypad and controls the intensity of red, green, and blue LEDs.
      analogWrite(6, R);
      analogWrite(3, G);
      analogWrite(5, B);
    }
  }
  //This thing here see witch number your holding and disable it
  if (holdNumber[0] == 1){
    rgbLights1();
    rgbLights2();
    rgbLights3();
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 0
    if (holdNumber[0] != 1){ // this for Taking your finger off the key will reset the number, but not the lights
      shutdonwLights(); //turn off lights function
    }
  }else if(holdNumber[1] == 1){
    R = 255; G = 0;   B = 0;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 1
    shutdonwLights();
  }else if(holdNumber[2] == 1){
    R = 0; G = 255;   B = 0;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 2
    shutdonwLights();
  }else if(holdNumber[3] == 1){
    R = 0; G = 0;   B = 255;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 3
    shutdonwLights();
  }else if(holdNumber[4] == 1){
    R = 255; G = 255;   B = 0;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 4
    shutdonwLights();
  }else if(holdNumber[5] == 1){
    R = 255; G = 0;   B = 255;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 5
    shutdonwLights();
  }else if(holdNumber[6] == 1){
    R = 0; G = 255;   B = 255;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 6
    shutdonwLights();
  }else if(holdNumber[7] == 1){
    R = 0; G = 55;   B =11;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 7
    shutdonwLights();
  }else if(holdNumber[8] == 1){
    R = 55; G = 155;   B = 255;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 8
    shutdonwLights();
  }else if(holdNumber[9] == 1){
    R = 11; G = 11;   B = 11;
    analogWrite(6, R); analogWrite(3, G); analogWrite(5, B); //COLOR OF NUMBER 9
    shutdonwLights();
  }
}
