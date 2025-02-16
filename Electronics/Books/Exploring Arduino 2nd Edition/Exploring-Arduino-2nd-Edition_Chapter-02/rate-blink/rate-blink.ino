// set the pin 9 first as LED
const int LED = 9;

void setup(void) {
  pinMode(LED, OUTPUT);     // set the PIN 9 as the output
}

void loop(void) {
  for (int i = 200; i <= 2000; i += 100) {
    digitalWrite(LED, HIGH);    // TURN ON THE LED
    delay(i);                   // FOR ABOUT i SECONDS
    digitalWrite(LED, LOW);     // TURN OFF THE LED
    delay(i);                   // FOR ABOUT i SECONDS
  }
}