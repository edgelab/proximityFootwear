//VabrationFootware
//By: Vlad Cazan
//EDGE Lab, Ryerson University 


const int pwPin = 7; 

long pulse, inches, cm;

int value; 

void setup() {
  Serial.begin(9600);
}
void loop() {
  pinMode(pwPin, INPUT);
  //Used to read in the pulse that is being sent by the MaxSonar device.
  //Pulse Width representation with a scale factor of 147 uS per Inch.

  pulse = pulseIn(pwPin, HIGH);
  //147uS per inch
  inches = pulse/147;
  //change inches to centimetres
  cm = inches * 2.54;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1);
//If function checks if there is any objects within 40 cm of the sensor. If there is calculate the power of the motor.
  if (cm < 40){
    value = (-1*(map(cm, 12,40, -255,0))); //The closer the object the faster the motor should spin. 
    Serial.print(value);
    Serial.println();
    analogWrite(9, value);

  }
  else{
    analogWrite(9, 0); //If there is nothing within 40 cm then make sure the motor is off. 
  }
}

