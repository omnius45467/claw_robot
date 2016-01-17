#include <MakeItRobotics.h> //include library
MakeItRobotics boxer; //declare object

#include <Servo.h>
#define pingInit


Servo baseServo;  // create servo object to control a servo
Servo elbowServo;
Servo gripServo;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(10420);
  baseServo.attach(9);  // attaches the servo on pin 9 to the servo object
  elbowServo.attach(8);
  gripServo.attach(7);
  delay(50);
}

void loop() {
  elbowServo.write(45);
  baseServo.write(90);
  delay(500);
  
  long distance = ping();
  
  if(distance >= 20){
    
    long distanceLow = ping();
    long distanceHigh = ping();
    
    gripServo.write(0);
    elbowServo.write(0);
    distanceLow;
    boxer.go_forward(200);
    
      for (pos = 10; pos <= 60; pos += 1) { // goes from 30 degrees to 60 degrees
        // in steps of 1 degree
        elbowServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 10ms for the servo to reach the position
      }
      distanceHigh;
      if(distanceLow > distanceHigh){
        boxer.go_forward(0);
        boxer.go_backward(200);
        delay(50);
      }else{
        boxer.go_forward(200);
        boxer.go_backward(0);
        delay(50);
      }
      
    delay(10);
  }else{
    boxer.go_forward(0);
    long distance1 = ping();
    long distance2 = ping();
    
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        baseServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 10ms for the servo to reach the position
      }
      distance1;
      delay(50);
      
      for (pos = 0; pos >= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        baseServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 10ms for the servo to reach the position
      }
      distance2;
      delay(50);
      
    if(distance1 < distance2){
      boxer.turn_right(200);
      delay(50);
    }else{
      boxer.turn_left(200);
      delay(50);
    }
    
    if(distance <= 10){
      gripServo.write(180);
      delay(10);
    
    }
    
    delay(10); 
    
  }
  
  delay(5);
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    baseServo.write(pos);              // tell servo to go to position in variable 'pos'
//    elbowServo.write(pos);
//    gripServo.write(pos);
//    delay(10);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    baseServo.write(pos);              // tell servo to go to position in variable 'pos'
//    elbowServo.write(pos);
//    gripServo.write(pos);
//    delay(10);                       // waits 15ms for the servo to reach the position
//  }
}
