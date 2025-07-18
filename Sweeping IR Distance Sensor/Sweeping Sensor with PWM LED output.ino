const int IR = A0;  
const int SERVO = 9; 
#include <Servo.h>
const int LED1=3;
const int LED2=5;
const int LED3=6;
const int LED4=11;

Servo myServo;
int distance1=0;
int distance2=0;
int distance3=0;
int distance4=0;

int readDistance(int position){
  myServo.write(position);
  delay(1000);
  int distance=analogRead(IR);
  distance=map(distance, 50, 500, 0, 255);
  return distance;
}

void setup(){
  	myServo.attach(SERVO);
	pinMode(LED1,OUTPUT);
 	pinMode(LED2,OUTPUT);
	pinMode(LED3,OUTPUT);
	pinMode(LED4,OUTPUT);
}

void loop(){
	distance1=readDistance(15);
  	analogWrite(LED1,distance1);
  	delay(2000);
	
  	distance2=readDistance(65);
  	analogWrite(LED2,distance2);
  	delay(2000);
  
  	distance3=readDistance(115);
  	analogWrite(LED3,distance3);
  	delay(2000);
  
  	distance4=readDistance(165);
  	analogWrite(LED4,distance4);
  	delay(2000);
  
  
}
