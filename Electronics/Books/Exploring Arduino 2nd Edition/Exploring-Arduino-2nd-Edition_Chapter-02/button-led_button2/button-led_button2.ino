const int LED = 9;    // set the LED to connect to PIN 9
const int BUTTON = 2; // set the BUTTON to connect to PIN 2
bool keepOn = 0;

void setup() {
  pinMode(LED, OUTPUT);       // set the LED as the OUTPUT VOLTAGE
  pinMode(BUTTON, INPUT);     // set the BUTTON as the INPUT
}

void loop(void) {  
  if (digitalRead(BUTTON) == HIGH && digitalRead(LED) == LOW)
    keepOn = 1;
    
  while (keepOn) {
    digitalWrite(LED, HIGH);
    if (digitalRead(BUTTON) == HIGH)
      break;
  }
}