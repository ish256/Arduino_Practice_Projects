const int sensorPin = A1;
const int moistureAO = 0;
int AO = 0;
int tmp = 0;
int buzzPin = 11;
int LED = 13;

void setup () {
  
  Serial.begin(9600); //send arduino reading to IDE
  Serial.println("Soil moisture sensor");
  pinMode(moistureAO, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(LED,OUTPUT);

}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = ((sensorVal)/1024.0)*5.0;
  float temperature = (voltage - .5)*100;
  Serial.println("temperature: ");
  Serial.println(temperature);

  tmp = analogRead( moistureAO );

  if (tmp != AO) {
  AO = tmp;
  Serial.print("\t A = ");
  Serial.println(AO);

  }
  
  delay( 1000 );

  if (analogRead(moistureAO) > 900 ) {
    digitalWrite(buzzPin, HIGH);
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(buzzPin,LOW);
    digitalWrite(LED, LOW);

  }
  else {
    digitalWrite(buzzPin,LOW);
    digitalWrite(LED, LOW);
  }
}


