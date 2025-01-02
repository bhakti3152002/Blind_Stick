#include <Servo.h>

const int trigPin = 7;   
const int echoPin = 8;   
const int ledPin = 6;    
const int buzzerPin = 5; 
const int servoPin = 9;   

Servo myServo; 

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    
    myServo.attach(servoPin);
    Serial.begin(9600); 
}

void loop() {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.034) 

    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 20) { 
        digitalWrite(ledPin, HIGH); 
        digitalWrite(buzzerPin, HIGH); 
        myServo.write(90); 
    }
 Else
 {
        digitalWrite(ledPin, LOW); 
        digitalWrite(buzzerPin, LOW); 
        myServo.write(0); 
    }
    
  delay(500); 
}
