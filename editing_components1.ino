const int enable = 9;
const int input1 = 5;
const int input2 = 4;
const int POT = 0;

void forward(int rate) {
  digitalWrite(enable, LOW);
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  analogWrite(enable, rate);
}

void reverse(int rate) {
  digitalWrite(enable, LOW);
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  analogWrite(enable, rate);
}

void brake() {
  digitalWrite(enable, LOW);
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(enable, HIGH);
}

void setup() {
  pinMode(enable, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(POT);

  if (value > 562) {
    int speed = map(value, 563, 1023, 0, 255);
    reverse(speed);
  } else if (value < 462) {
    int speed = map(value, 461, 0, 0, 255);
    forward(speed);
  } else {
    brake();
  }
}
