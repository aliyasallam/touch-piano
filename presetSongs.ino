//declare and initialize the frequencies of different notes
  const int bF = 233;
  const int b = 247;
  const int c = 261;
  const int d = 294;
  const int dS = 311;
  const int e = 329;
  const int f = 349;
  const int fS = 370;
  const int g = 391;
  const int gS = 415;
  const int a = 440;
  const int aS = 455;
  const int b2 = 494;
  const int c2 = 523;
  const int cS2 = 554;
  const int d2 = 587;
  const int dS2 = 622;
  const int e2 = 659;
  const int f2 = 698;
  const int fS2 = 740;
  const int g2 = 784;
  const int gS2 = 830;
  const int a2 = 880;
  const int aS2 = 932;
  const int c3 = 1046;

//array of the notes in Star Wars
  int starWarsMel[] = {d, d, d, g, d2, 
                    c2, b2, a, g2, d2, 
                    c2, b2, a, g2, d2,
                    c2, b2, c2, a, 
                    d, d, g, d2, 
                    c2, b2, a, g2, d2, 
                    g2, f2, dS2, aS2, a2, g2, 
                    g, g, g, g};

//array of the note values in Star Wars                 
  float starWarsDur[]  = {.33, .33, .33, 2, 2, 
                        .33, .33, .33, 2, 1, 
                        .33, .33, .33, 2, 1, 
                        .33, .33, .33, 2,   
                        .75, .25, 2, 2, 
                        .33, .33, .33, 2, 1,
                        .33, .33, .33, 2, 2, 1, 
                        .33, .33, .33, 1};  

//size of the arrays above                   
  int starWarsSize = 38;     

//plays Star Wars
void starWars(){
  int tempo = 500;      //set tempo
  //loop through all of the notes
  for(int note = 0; note < starWarsSize; note++){
    //set note duration in milliseconds
    float duration = tempo * starWarsDur[note];

    //play note on buzzer for correct duration
    tone(buzzerPin, starWarsMel[note], duration);
    
    //pause equal to 30% longer than note duration (so you can differentiate between the note and the next note)
    delay(duration * 1.3);
  }

  noTone(buzzerPin);
}

//array containing notes in Harry Potter
int harryPotterMel[]{b, e, g, fS, e, b2, a, fS,
                     e, g, fS, d, f, b, 0,
                     b, e, g, fS, e, b2, 
                     d2, cS2, c2, gS, 
                     c2, b2, gS, bF, g, e};

//array containing note values in Harry Potter                                                          
float harryPotterDur[]{1, 1.5, .5, 1, 2, 1, 3, 3, 
                       1.5, .5, 1, 2, 1, 3, 2, 
                       1, 1.5, .5, 1, 2, 
                       1, 2, 1, 2, 1,
                       1.5, .5, 1, 2, 1, 3}; 
                               

//size of above arrays
int harryPotterSize = 31;


//plays Harry Potter
void harryPotter(){
  int tempo = 400;     //set tempo (in milliseconds)
  //loop through all of the notes
  for(int note = 0; note < harryPotterSize; note++){
    //set note duration
    float duration = tempo * harryPotterDur[note];

    //play note and pause after
    tone(buzzerPin, harryPotterMel[note], duration);
    delay(duration * 1.3);
  }

  noTone(buzzerPin);
}

//array with notes in Frozen
int snowmanMel[] = {dS2, dS2, dS2, aS, dS2, g2, f2, g2, 0,                    
                    dS2, dS2, aS, dS2, g2, f2, 0,                              
                    dS2, dS2, aS, dS2, g2, gS2, g2, dS2, 
                    aS, gS2, g2, dS2, dS2, dS2, aS, dS2, g2, aS2, 0,    
                    aS2, aS2, gS2, g2, gS2, aS2, dS2,        
                    dS2, f2, g2, dS2, f2,         
                    g2,  f2, dS2, f2, g2, c3, 0,                
                    dS2, dS2, dS2, aS, dS2, g2, f2, g2, 0,     
                    dS, dS, dS, bF, dS, g, f, dS};           

//array with note values in Frozen
float snowmanDur[] = {.5, .5, .5, .5, .5, .5, 1, 2, .5,
                      .5, .5, .5, .5, .5, 3, .5,
                      .5, .5, .5, .5, .5, .5, .5, 1.5,
                      .5, .5, .5, 1.5, .5, .5, .5, .5, .5, 4, .5,
                      .5, .5, .5, .5, .5, .5, 3,
                      .5, 1, .5, 2, .5, 
                      .66, .66, .66, 1, 1, 4, 1,
                      .5, .5, .5, .5, .5, .5, 1, 2, .5, 
                      .5, .5, .5, .5, .5, .5, 1, 3};                

//size of above arrays
int snowmanSize = 71;  

//play Do You Want to Build a Snowman                 
void snowman(){
  int tempo = 400;          //set tempo
  //loop through all notes
  for(int note = 0; note < snowmanSize; note++){
    //set note duration
    float duration = tempo * snowmanDur[note];

    //play note and pause after
    tone(buzzerPin, snowmanMel[note], duration);
    delay(duration * 1.3);
  }

  noTone(buzzerPin);
}

