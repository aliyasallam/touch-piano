//checks if any of the buttons were pressed
void buttonPressed(int button){
  //if first button was pressed down                               //each button is connected with a different resistor,
  if(button > 1020 && !b1){                                        //which prints different values based off of which was pressed
    b1 = true;
  } 
  //if second button was pressed down
  else if(button > 900 && button < 1010 && !button2){
    button2 = true;
  }
  //if button was released/not pressed
  else if(button < 500){
    //checks if button 1 is true and switches screen
    if(b1){
      switchScreen = true;
      b1 = false;
    }
    //checks if button 2 is true and plays/pauses the song
    else if(button2){
      playSong = !playSong;
      button2 = false;
    }
  }
}

//switches the display
void switchDisplay(){
  //iterates through possible screens
  for(int i = 0; i < displayNum; i++){
    //finds the index value of the current screen
      if(screen[i] == current){   
        //if screen is the last element, set new screen to first element         
        if(i == displayNum-1){
          current = screen[0];
          currentNum = 0;
        }
        //else increase the screen by one
        else{
          current = screen[i+1];
          currentNum = i+1;
        }
        break;
      }
    }
    
    //resets playSong so any song stops playing
    playSong = false;

    //puts the string in current (aka the new display) into a buffer and prints it to the screen
    char buff[33];
    current.toCharArray(buff, current.length()+1);   
    lcd.clear();
    lcd.print(buff);
}

//plays the correct song or the theremin
void play(){
  if(currentNum == 0){
    tone(13, pitch, 20);            //turns on the theremin
  }
  else if(currentNum == 1){        //plays the Star Wars main theme
    starWars();
    playSong = false;
  }
  else if(currentNum == 2){        //plays the Harry Potter theme
    harryPotter();
    playSong = false;
  }
  else if(currentNum == 3){        //plays Do You Want to Build a Snowman from Frozen
    snowman();
    playSong = false;
  }
}
