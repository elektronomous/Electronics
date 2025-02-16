const int rightBUTTON = 2;
const int leftBUTTON = 4;
const int leftLED = 10;
const int rightLED = 9;

void setup(void) {
  pinMode(rightBUTTON, INPUT);
  pinMode(leftBUTTON, INPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
}

void loop(void) {
  if(digitalRead(rightBUTTON) == HIGH) {
    digitalWrite(rightLED, HIGH);
    digitalWrite(leftLED, LOW);
  } 

  if (digitalRead(leftBUTTON) == HIGH) {
    digitalWrite(leftLED, HIGH);
    digitalWrite(rightLED, LOW);
  }

  if (digitalRead(rightBUTTON) == HIGH && digitalRead(leftBUTTON) == HIGH) {
    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, LOW);
  }
}