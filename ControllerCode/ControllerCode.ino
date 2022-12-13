#include <Servo.h>  // add servo library
 
Servo myservo1;  // create servo object to control a servo 1
Servo myservo2;  // create servo object to control a servo 2
Servo myservo3;  // create servo object to control a servo 3
Servo myservo4;  // create servo object to control a servo 4
Servo myservo5;  // create servo object to control a servo 5
Servo myservo6;  // create servo object to control a servo 6
 
int potpin1 = 0;  // analog pin used to connect the potentiometer
int val1p;    // variable to read the value from the analog pin
int val1;    // variable to read the value from the analog pin
int potpin2 = 1;  // analog pin used to connect the potentiometer
int val2p;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin
int potpin3 = 2;  // analog pin used to connect the potentiometer
int val3p;    // variable to read the value from the analog pin
int val3;    // variable to read the value from the analog pin
int potpin4 = 3;  // analog pin used to connect the potentiometer
int val4p;    // variable to read the value from the analog pin
int val4;    // variable to read the value from the analog pin
int potpin5 = 4;  // analog pin used to connect the potentiometer
int val5p;    // variable to read the value from the analog pin
int val5;    // variable to read the value from the analog pin
int potpin6 = 5;  // analog pin used to connect the potentiometer
int val6p;    // variable to read the value from the analog pin
int val6;    // variable to read the value from the analog pin
int read;



 
void setup() {
  myservo1.attach(2);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(4);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo5.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo6.attach(7);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}
 
void loop() {
  val1p = analogRead(potpin1);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10);  
  val1 = analogRead(potpin1);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10); 
  val1 = (val1+val1p)/2;
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo1.write(val1);                  // sets the servo position according to the scaled value
  
  delay(10);                           // waits for the servo to get there

  val2p = analogRead(potpin2);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10);  
  val2 = analogRead(potpin2);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10); 
  val2 = (val2+val2p)/2;
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo2.write(val2);                  // sets the servo position according to the scaled value

  delay(10);   

  val3p = analogRead(potpin3);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10);  
  val3 = analogRead(potpin3);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10); 
  val3 = (val3+val3p)/2;
  val3 = map(val3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo3.write(val3);                  // sets the servo position according to the scaled value
  delay(10);
  
  val4p = analogRead(potpin4);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10);  
  val4 = analogRead(potpin4);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10); 
  val4 = (val4+val4p)/2;
  val4 = map(val4, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo4.write(val4);                  // sets the servo position according to the scaled value
  delay(10);

  val5p = analogRead(potpin5);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10);  
  val5 = analogRead(potpin5);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10); 
  val5 = (val5+val5p)/2;
  val5 = map(val5, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo5.write(val5);                  // sets the servo position according to the scaled value
  delay(10);

  val6p = analogRead(potpin6);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10);  
  val6 = analogRead(potpin6);          // reads the value of the potentiometer (value between 0 and 1023)
  delay(10); 
  val6 = (val6+val6p)/2;
  val6 = map(val6, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo6.write(val6);                  // sets the servo position according to the scaled value
  delay(10);

  /*Serial.print("POT1 : ");
  Serial.print(val1);
  Serial.print("\n");

  Serial.print("POT2 : ");
  Serial.print(val2);
  Serial.print("\n");

  Serial.print("POT3 : ");
  Serial.print(val3);
  Serial.print("\n");

  Serial.print("POT4 : ");
  Serial.print(val4);
  Serial.print("\n");

  Serial.print("POT5 : ");
  Serial.print(val5);
  Serial.print("\n");

  Serial.print("POT6 : ");
  Serial.print(val6);
  Serial.print("\n");
Serial.print("-------------------------\n");
  delay(1000);*/
  
}
