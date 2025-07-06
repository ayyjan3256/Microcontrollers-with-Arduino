const int RLED = 11;
const int GLED = 10;
const int BLED = 9;
const int BUTTON = 7;

int ledMode = 0;
bool lastButton = LOW;
bool currentButton = LOW;

void setup() {
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);
  if (current != last) {
    delay(50);
    current = digitalRead(BUTTON);
  }
  return current;
}

void setMode(int mode) {
  if (mode == 0) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);  // Blue ON
  } else if (mode == 1) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);  // Green ON
  } else if (mode == 2) {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);  // Red ON
  } else if (mode == 3) {
    analogWrite(RLED, 127);
    analogWrite(GLED, 255);
    analogWrite(BLED, 127);    // Mixed color
  }
}

void loop() {
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {
    ledMode++;
    if (ledMode > 3) ledMode = 0;
  }
  lastButton = currentButton;
  setMode(ledMode);
}
