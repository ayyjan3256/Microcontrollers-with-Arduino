const int GLED = 10;
const int RLED = 11;
const int BLED = 9;
const int POT = A0;

void setup() {
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  Serial.begin(9600);
}

void setMode(float voltage) {
  if (voltage < 1.5) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  } else if (voltage > 1.5 && voltage < 4) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  } else {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
}

void loop() {
  int value = analogRead(POT);
  float voltage = (value * 5.0) / 1023.0;
  Serial.print("Voltage: ");
  Serial.println(voltage, 2);
  setMode(voltage);
  delay(2000);
}
