int threshold;       //minimum value required on touch sensor for note to play

//send information from touch sensors to the serial port, which will then be read by processing
void sendPianoInfo(){
  bool noteSent = false;
  
  //iterates through all keys
  for(int i = 0; i < 8; i++){
    //gets sensor value from each key
    long value = sensor[i]->capacitiveSensor(30);
    //Serial.println(value);                       //for testing
    //delay(100);
    //since key 8 (high C) is way more sensitive than the other keys, adjust the threshold accordingly
    if(i == 8){
      threshold = 9000;
    }
    else{
      threshold = 400;
    }
    //checks if the key is being pressed and if so, sends the key number (1 to 8) to the serial port
    if(value > threshold){    
      Serial.println(i+1);
      noteSent = true;
      break;
    }
  }
  //sends 0 to serial port if no key was pressed
  if(!noteSent){
    Serial.println(0);
  }
}
