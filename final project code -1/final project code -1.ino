#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

#define PICKINGR1  0
#define PICKINGR2  60
#define PICKINGR3  0
#define PICKINGR4  125
#define PICKINGR5  103
#define PICKINGR6  110
//---------------------
#define DROPINGGREENR1  170
#define DROPINGGREENR2  90
#define DROPINGGREENR3  12
#define DROPINGGREENR4  73
#define DROPINGGREENR5  103
#define DROPINGGREENR6  20
//-----------------------
#define DROPINGREDR1  93
#define DROPINGREDR2  90
#define DROPINGREDR3  12
#define DROPINGREDR4  73
#define DROPINGREDR5  103
#define DROPINGREDR6  20
//-----------------------
#define DROPINGBLUER1  40
#define DROPINGBLUER2  90
#define DROPINGBLUER3  12
#define DROPINGBLUER4  73
#define DROPINGBLUER5  103
#define DROPINGBLUER6  20

//------------------------
#define REDLED 22
#define YELLOWLED 24
#define BLUELED 31 
void setup()
{
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);
  pinMode(REDLED,OUTPUT);
  pinMode(YELLOWLED,OUTPUT);
  pinMode(BLUELED,OUTPUT);
  digitalWrite(REDLED,LOW);
  digitalWrite(YELLOWLED,LOW);
  digitalWrite(BLUELED,LOW);
  Serial.begin(9600);
}

void loop()
{
  int response = 0;
  if(Serial.available()){
    response = Serial.read();
  }
  
  switch(response){
  digitalWrite(REDLED,LOW);
  digitalWrite(YELLOWLED,LOW);
  digitalWrite(BLUELED,LOW);
    case 1:
      //RED
      digitalWrite(REDLED,HIGH);
      Picking();
      DropRed();
      digitalWrite(REDLED,LOW);
      break;
    case 2:
      //YELLOW
      digitalWrite(YELLOWLED,HIGH);
      Picking();
      DropGreen();
      digitalWrite(YELLOWLED,LOW);
      break;
    case 3:
      //BLUE
      digitalWrite(BLUELED,HIGH);
      Picking();
      DropBlue();
      digitalWrite(BLUELED,LOW);
      break;
    default:
      break;
  }
}
void Picking(){
//PICKING FUNCTION
  for(int i=0;i<=PICKINGR1;i++){
  servo1.write(i);
  delay(35);
  } 
  for(int i=90;i>=PICKINGR3;i--){
  servo3.write(i);
  delay(35);
  } 
  for(int i=0;i<=PICKINGR4;i++){
  servo4.write(i);
  delay(35);
  } 

  servo6.write(0);
  for(int i=0;i<=PICKINGR5;i++){
  servo5.write(i);
  delay(35);
  } 

  for(int i=90;i>=PICKINGR2;i--){
  servo2.write(i);
  delay(35);
  } 
  for(int i=0;i<=PICKINGR5;i++){
  servo6.write(i);
  delay(35);
  } 

}
void DropGreen(){
  //DROPING FINCTION IF GREEN
  if(PICKINGR2<DROPINGGREENR2){
    for(int i=PICKINGR2;i<=DROPINGGREENR2;i++){
    servo2.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR2;i>=DROPINGGREENR2;i--){
    servo2.write(i);
    delay(35);
    } 
  }
if(PICKINGR1<DROPINGGREENR1){
    for(int i=PICKINGR1;i<=DROPINGGREENR1;i++){
    servo1.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR1;i>=DROPINGGREENR1;i--){
    servo1.write(i);
    delay(35);
  } 
} 
if(PICKINGR3<DROPINGGREENR3){
    for(int i=PICKINGR3;i<=DROPINGGREENR3;i++){
    servo3.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR3;i>=DROPINGGREENR3;i--){
    servo3.write(i);
    delay(35);
    } 
  }
  if(PICKINGR4<DROPINGGREENR4){
    for(int i=PICKINGR4;i<=DROPINGGREENR4;i++){
    servo4.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR4;i>=DROPINGGREENR4;i--){
    servo4.write(i);
    delay(35);
    } 
  }
  for(int i=PICKINGR6;i>=0;i--){
  servo6.write(i);
  delay(35);
  }

}
void DropRed(){
  //DROPING FINCTION IF RED
  if(PICKINGR2<DROPINGREDR2){
    for(int i=PICKINGR2;i<=DROPINGREDR2;i++){
    servo2.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR2;i>=DROPINGREDR2;i--){
    servo2.write(i);
    delay(35);
    } 
  }
if(PICKINGR1<DROPINGGREENR1){
    for(int i=PICKINGR1;i<=DROPINGREDR1;i++){
    servo1.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR1;i>=DROPINGREDR1;i--){
    servo1.write(i);
    delay(35);
  } 
} 
if(PICKINGR3<DROPINGREDR3){
    for(int i=PICKINGR3;i<=DROPINGREDR3;i++){
    servo3.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR3;i>=DROPINGREDR3;i--){
    servo3.write(i);
    delay(35);
    } 
  }
  if(PICKINGR4<DROPINGREDR4){
    for(int i=PICKINGR4;i<=DROPINGREDR4;i++){
    servo4.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR4;i>=DROPINGREDR4;i--){
    servo4.write(i);
    delay(35);
    } 
  }
  for(int i=PICKINGR6;i>=0;i--){
  servo6.write(i);
  delay(35);
  }
}
void DropBlue(){
  if(PICKINGR2<DROPINGBLUER2){
    for(int i=PICKINGR2;i<=DROPINGBLUER2;i++){
    servo2.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR2;i>=DROPINGBLUER2;i--){
    servo2.write(i);
    delay(35);
    } 
  }
if(PICKINGR1<DROPINGBLUER1){
    for(int i=PICKINGR1;i<=DROPINGBLUER1;i++){
    servo1.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR1;i>=DROPINGBLUER1;i--){
    servo1.write(i);
    delay(35);
  } 
} 
if(PICKINGR3<DROPINGBLUER3){
    for(int i=PICKINGR3;i<=DROPINGBLUER3;i++){
    servo3.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR3;i>=DROPINGBLUER3;i--){
    servo3.write(i);
    delay(35);
    } 
  }
  if(PICKINGR4<DROPINGBLUER4){
    for(int i=PICKINGR4;i<=DROPINGBLUER4;i++){
    servo4.write(i);
    delay(35);
    } 
  }
  else{
    for(int i=PICKINGR4;i>=DROPINGBLUER4;i--){
    servo4.write(i);
    delay(35);
    } 
  }
  for(int i=PICKINGR6;i>=0;i--){
  servo6.write(i);
  delay(35);
  }
}
