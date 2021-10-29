int MetalDetector = 0;

int DistanceLeft = 0;

int DistanceFront = 0;

int DistanceRight = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()

{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop()
{
  
//Metaldetector
 
    MetalDetector = digitalRead(2);
  if (MetalDetector == 1) {
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 0);
    analogWrite(10, 0);    
    delay(2000);
    digitalWrite(13, LOW);
    analogWrite(5, 180);
    analogWrite(6, 0);
    analogWrite(9, 180);
    analogWrite(10, 0);
    delay(500);

} else {
    digitalWrite(13, HIGH);
}    
   
//read Distance

  DistanceLeft = 0.01723 * readUltrasonicDistance(3, 4);
  DistanceFront = 0.01723 * readUltrasonicDistance(7, 8);
  DistanceRight = 0.01723 * readUltrasonicDistance(11, 12);

//Forward

    if (DistanceLeft > 15 && (DistanceFront > 15 && (DistanceRight > 15))) {
      Serial.println("Forward:");  
      Serial.println(DistanceLeft);
      Serial.println(DistanceFront);   
      Serial.println(DistanceRight);    
      analogWrite(5, 220);
      analogWrite(6, 0);
      analogWrite(9, 220);
      analogWrite(10, 0);
      delay(150);
      
    }
    
//backward

    if (DistanceLeft < 10 && (DistanceFront > 1500 && (DistanceRight > 1500 || (DistanceLeft > 1500 && (DistanceFront > 1500 && (DistanceRight > 1500 )))))){
      Serial.println("Back:");  
      Serial.println(DistanceLeft);
      Serial.println(DistanceFront);   
      Serial.println(DistanceRight);      
      analogWrite(5, 0);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(10, 0);
      delay(250);
      analogWrite(5, 0);
      analogWrite(6, 180);
      analogWrite(9, 0);
      analogWrite(10, 180);
      delay(1000);
      analogWrite(5, 0);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(10, 0);
      delay(250);
      analogWrite(5, 255);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(10, 255);
      delay(750);
    }
    
  if (DistanceFront < 40) {
    
//TurnRight

    if (DistanceLeft < 15 && DistanceRight >= 35) {
      Serial.println("Right:");  
      Serial.println(DistanceLeft);
      Serial.println(DistanceFront);   
      Serial.println(DistanceRight); 
      analogWrite(5, 0);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(10, 0);
      delay(250);
      analogWrite(5, 0);
      analogWrite(6, 180);
      analogWrite(9, 0);
      analogWrite(10, 180);
      delay(700);
      analogWrite(5, 0);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(10, 0);
      delay(250); 
      analogWrite(5, 0);
      analogWrite(6, 255);
      analogWrite(9, 255);
      analogWrite(10, 0);
      delay(550);
    }
    
//TurnLeft

    if (DistanceLeft >= 35 && DistanceRight < 15) {
      Serial.println("Left:");  
      Serial.println(DistanceLeft);
      Serial.println(DistanceFront);   
      Serial.println(DistanceRight);      
      analogWrite(5, 0);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(10, 0);
      delay(250);
      analogWrite(5, 0);
      analogWrite(6, 180);
      analogWrite(9, 0);
      analogWrite(10, 180);
      delay(700);
      analogWrite(5, 0);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(10, 0);
      delay(250);
      analogWrite(5, 255);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(10, 255);
      delay(550);
    }

//emergency backward  
   
   }
   if (DistanceFront < 5 || DistanceFront > 2000) {
    Serial.println("BackBank:");  
    Serial.println(DistanceLeft);
    Serial.println(DistanceFront);   
    Serial.println(DistanceRight);  
    analogWrite(5, 0);
    analogWrite(6, 180);
    analogWrite(9, 0);
    analogWrite(10, 180);
    delay(250);
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 0);
    analogWrite (10, 0);
    delay(100);
    analogWrite(5, 255);
    analogWrite(6, 0);
    analogWrite(9, 0);
    analogWrite(10, 255);
    delay(550);
  }
}
