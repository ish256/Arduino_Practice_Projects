int switchState = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);

}

//note this loop happens really fast...
void loop() {
  // put your main code here, to run repeatedly:

  //read in the state at port 2 
  switchState = digitalRead(2);

  //if the state is high (meaning that power is flowing in)
  //then push power out through port 3 and block power out 
  // for ports 3 and 4
  if (switchState == LOW) {

    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    
  }
  else {
    //if state is low (meaning that power isn't flowing in)
    //then stop power flow at port 3 and alternate flow 
    //for ports 4 and 5 
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);


    delay(250);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
    
  }
}
