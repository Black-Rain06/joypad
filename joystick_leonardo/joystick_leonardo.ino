// Simple gamepad example that demonstraits how to read five Arduino
// digital pins and map them to the Arduino Joystick library.
//
// The digital pins 2 - 6 are grounded when they are pressed.
// Pin 2 = UP
// Pin 3 = RIGHT
// Pin 4 = DOWN
// Pin 5 = LEFT
// Pin 6 = FIRE
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2016-11-24
//--------------------------------------------------------------------

#include <Joystick.h>

#define joybutton1 2
#define joybutton2 3
#define joybutton3 4
#define joybutton4 5

//JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD
Joystick_ Joystick(0x15,JOYSTICK_TYPE_JOYSTICK,
  4, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering


const bool initAutoSendState = true;

int lastbuttonstate1 = 0;
int lastbuttonstate2 = 0;
int lastbuttonstate3 = 0;
int lastbuttonstate4 = 0;

void setup() {
  
  // Initialize Button Pins
  pinMode(joybutton1, INPUT_PULLUP);
  pinMode(joybutton2, INPUT_PULLUP);
  pinMode(joybutton3, INPUT_PULLUP);
  pinMode(joybutton4, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
}

// Last state of the buttons
//int lastButtonState[5] = {0,0,0,0,0};

void loop() {

  // Read pin values
  int currentButton1state = !digitalRead(joybutton1);
  if (currentButton1state != lastbuttonstate1){
    Joystick.setButton(0, currentButton1state);
    lastbuttonstate1 = currentButton1state;
  }

  int currentButton2state = !digitalRead(joybutton2);
  if (currentButton2state != lastbuttonstate2){
    Joystick.setButton(1, currentButton2state);
    lastbuttonstate2 = currentButton2state;
  }

  int currentButton3state = !digitalRead(joybutton3);
  if (currentButton3state != lastbuttonstate3){
    Joystick.setButton(2, currentButton3state);
    lastbuttonstate3 = currentButton3state;
  }

  int currentButton4State = !digitalRead(joybutton4);
  if (currentButton4State != lastbuttonstate4){
    Joystick.setButton(3, currentButton4State);
    lastbuttonstate4 = currentButton4State;
  }
  delay(10);
}
