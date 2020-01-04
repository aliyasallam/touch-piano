/* Aliya Sallam
 * ICS4U
 * June 15, 2018
 * Independent Studies Project
 * Arduino Touch Piano, Theremin, and Song Playback
 */

#include <CapacitiveSensor.h>
#include <LiquidCrystal.h>

CapacitiveSensor* sensor[8];         //sensor for each key

//liquid crystal display pins
const int rs = 12, en = 11, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//display variables
bool b1 = false;
bool button2 = false;
bool switchScreen = false;
bool playSong = false;
int displayNum = 4;
String screen[] = {"Theremin", "Star Wars", "Harry Potter", "Snowman"};
String current;
int currentNum = 0;

//theremin variables
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
int pitch;
const int buzzerPin = 13;

void setup() {
  Serial.begin(9600);

  //calibrate the theremin
  calibrateTheremin();

  //initialize touch sensors (piano keys)
  for(int i = 0; i < 8; i++){
    sensor[i] = new CapacitiveSensor(2, i+3);
    sensor[i]->set_CS_AutocaL_Millis(0xFFFFFFFF);
  }

  //set current display to 0
  current = screen[0]; 

  //print display
  lcd.begin(16,2);
  lcd.print("Touch Piano!");
}

void loop(){ 
  //write piano information to serial for Processing to read
  sendPianoInfo();

  //calculate the theremin pitch based on light waves
  calculatePitch();

  //check if any of the buttons were pressed
  int button = analogRead(A1); 
  buttonPressed(button);

  //play song or switch screen accordingly
  if(switchScreen){
    switchDisplay();
  }
  switchScreen = false;

  if(playSong){
    play();
  }
  else{
    noTone(13);
  }
}




