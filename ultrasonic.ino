long ping(){
  long duration, cm;
  pinMode(53, OUTPUT);// attach pin 6 to Trig
  digitalWrite(53, LOW);
  delayMicroseconds(2);
  digitalWrite(53, HIGH);
  delayMicroseconds(5);
  digitalWrite(53, LOW);
  
  pinMode (51, INPUT);//attach pin 5 to Echo
  duration = pulseIn(51, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

  delay(10);
  return cm;
}


long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
