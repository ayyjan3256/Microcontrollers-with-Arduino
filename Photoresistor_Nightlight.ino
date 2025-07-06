const int LED=5;
const int POT=0;
void setup(){
  pinMode(LED,OUTPUT);
  pinMode(POT,INPUT);
  Serial.begin(9600);
  }
void loop(){
  float value=analogRead(POT);
  delay(200);
  float value1= (value*255)/1023;
  Serial.print(value1,2);
  Serial.print("   ");
  Serial.println(value,2);
  analogWrite(LED,value1);
  }
