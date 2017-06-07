  const int switchPin = 8;
  unsigned long previousTime = 0;
  int switchState = 0;
  int prevSwitchState = 0;
  int led =  2;
  long interval = 2000;
  int lightDir = 0;
  void setup() {

    for(int x = 2; x<8; x++) {

      pinMode(x, OUTPUT);
      
    }

    pinMode(switchPin, INPUT);
    
 }

void loop() {

  unsigned long currentTime = millis();
  
  if ( lightDir == 0) {

  if(currentTime-previousTime > interval) {
    previousTime = currentTime;
    
    digitalWrite(led, HIGH);

    led++;

   switchState = digitalRead(switchPin);

    if(led == 8) {

      for(int j = 1; j<10; j++) {
        
        for(int k = 2;k<8; k++) {
          
          delay(50);
          digitalWrite(k, LOW);
          delay(50);
          digitalWrite(k, HIGH);
          delay(50);
        }
      }

      if (switchState == 0){
        switchState = 1;
      }
      else {
        switchState = 0;
      }      
    }
  }
  
  if(switchState != prevSwitchState){

  for(int x = 2; x<8; x++){

      digitalWrite(x, LOW);
  }

  lightDir = 1;
  led = 2;
  
  previousTime = currentTime;
  
  }

  prevSwitchState = switchState;

  }
  
}
