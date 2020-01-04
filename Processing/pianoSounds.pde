import processing.serial.*;
import themidibus.*;              //library for piano sounds

Serial myPort;
MidiBus myMidi;
Note[] keyboard = {                   //stores note values for all eight keys
  new Note(0, 60, 127),
  new Note(0, 62, 127),
  new Note(0, 64, 127),
  new Note(0, 65, 127),
  new Note(0, 67, 127),
  new Note(0, 69, 127),
  new Note(0, 71, 127),
  new Note(0, 72, 127)
};

boolean pressed = false;
Note currentNote = keyboard[0];

//variables for wave
float size = 10;                 //size of circles of wave as well as the spacing between each x-value
float hShift = 0.0;              //horizontal shift (so wave looks like its moving across screen)
float amplitude;
float period = 200.0;            //pixels
float[] yValues;
float increaseX = (TWO_PI / period * size);       //how much to increase the x values by in radians

float nextValue;          //next note value

float r = 0;
float g = 0;
float b = 0;

void setup(){
  size(1000, 700);
  MidiBus.list();
    
  yValues = new float[101];
  
  //initialize serial port and midi player
  println("Available serial ports: ");
  println(Serial.list());
  myPort = new Serial(this, "COM3", 9600);
  myPort.bufferUntil('\n');
  myMidi = new MidiBus(this, 0, 1);
 
}

void draw(){
  background(0);
  //calculate y values for wave - nextValues sends note value to change the amplitude
  calculateWave(nextValue);
  
  noStroke();
  
  r = 0;
  g = 0;
  b = 0;
  
  //draw the wave
  for(int x = 0; x < yValues.length; x++){
    //change colour based on whether a key is pressed or not
    calculateColour(nextValue);
    
    //draw a small circle at each point on wave to display the pattern
    fill(r, g, b);
    ellipse(x*size, height/2+yValues[x], size, size);
  }
}

//reads in serial values
void serialEvent(Serial myPort){
  //checks that serial port is working
   while(myPort.available() > 0){
     //reads in the values of the serial port line by line (since 1 line = 1 key value from Arduino)
      nextValue = float(myPort.readStringUntil('\n'));
      println(nextValue);
      
      //if key is being pressed (>0) and it wasn't pressed before
      if(nextValue > 0 && !pressed){
        //play note (note sustains like a piano until turned off)
          startNote(keyboard[int(nextValue-1)]);
          pressed = true;                   //set pressed to true so that the note isn't turned on again while the key is still being pressed    
      }
      //turns note off when key is no longer pressed
      else if(pressed && nextValue == 0){
          endNote(currentNote);
          pressed = false;
       }
   }
}

//plays note that was pressed
void startNote(Note note){ 
  myMidi.sendNoteOn(note);
  currentNote = note;
}

//turns off note when key is depressed
void endNote(Note note){
  myMidi.sendNoteOff(note);
}

//calculate the y-values for the sound wave
void calculateWave(float noteValue){
  hShift += 0.03;                        //sine wave start position increases (shifts wave horizontally so it looks like it is moving left across the screen)
  amplitude = noteValue * 20;            //altitude changes based on note being played
  
  float x = 0;
  
  //calculates the y values for each point
  for(int i = 0; i < yValues.length; i++){             
    yValues[i] = sin(x + hShift) * amplitude;          //equation for sine wave
    x+=increaseX;                                      //increase x value by the correct number of radians
  }  
}

//calculate the colour of the circles in the wave
void calculateColour(float noteValue){
  //if no note is being played, wave is white
  if(noteValue == 0){
    r = 255;
    g = 255;
    b = 255;
  }
  //if note is played, set each circle to a different colour randomly (colours are in purple-blue spectrum)
  else{
    r = random(255);
    g = random(255);
    b = 255;
  }
}
