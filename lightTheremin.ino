//calibrates the theremin based on the amount of light (move hand around to calibrate
void calibrateTheremin(){
  lcd.clear();
  lcd.print("Calibrating...");

  while(millis() < 5000){                   //for five seconds
    //reads in the value from the light sensor  
    sensorValue = analogRead(A0);                  

    //adjusts the highest and lowest amount of light (to determine where highest and lowest pitches are)
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
}


//calculates the pitch of the theremin based on the amount of light it is sensing
void calculatePitch(){
  sensorValue = analogRead(A0);                                    //gets sensor value
  pitch = map(sensorValue, sensorLow, sensorHigh, 10, 3000);       //sets sensor value to a pitch within a certain range
}
