const int sensorPin = A0;
float baselineTemp = 0.0;
float numTempReads = 1;
float sumOfTemps = 0;

void setup() {
  Serial.begin(9600);//open a serial port

  for(int pinNumber = 2; pinNumber < 5 ; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  //for(int avgTempLoopInd = 1; avgTempLoopInd < 100 ; avgTempLoopInd++){
  // put your main code here, to run repeatedly:
  //int sensorVal = analogRead(sensorPin);
  //convert the ADC reading to voltage
  //float voltage = (sensorVal/1024.0) * 5.0;
  // convert the voltage to temperature in degrees
  //float temperature = (voltage - .5) * 100;

// baselineTemp = temperature + baselineTemp;
// }

//  baselineTemp = baselineTemp/99.0;
  
}




void loop() {
    int sensorValForAvg = analogRead(sensorPin);
    float voltageForAvg = (sensorValForAvg/1024.0) * 5.0;
    float currentTemp = (voltageForAvg - .5) * 100;
    sumOfTemps =  (currentTemp + sumOfTemps);
    baselineTemp = sumOfTemps/numTempReads;
    Serial.println("AVG Sensor Value: ");
    Serial.print(baselineTemp);
    Serial.println("Iter Num: ");
    Serial.print(numTempReads);

  
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  //convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  // convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);


  if(temperature < baselineTemp){

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

  }else if(temperature >= baselineTemp+2 && 
          temperature < baselineTemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

  }  else if(temperature >= baselineTemp+4 && 
          temperature < baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

   }else if(temperature >= baselineTemp+6 ) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
          }

   numTempReads = numTempReads +1;
  delay(1);
  }
