const int LED = 9;      // set the LED to connect on PIN 9
const int BUTTON = 2;   // set the BUTTON to connect on PIN 2

void setup(void) {
  pinMode(LED, OUTPUT);   // set the LED to be output (give voltage later)
  pinMode(BUTTON, INPUT); // set the BUTTON as the giver 
}

void loop(void) {
  if (digitalRead(BUTTON)== LOW) {
    digitalWrite(LED, LOW);
  } else { 
    digitalWrite(LED, HIGH);
  }
}