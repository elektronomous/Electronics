// set the pin 9 as the LED
const int LED = 9;

void setup(void) {
  pinMode(LED, OUTPUT);   // set the pin 9 as the output
}

void loop(void) {
  for (int i = 0; i < 256; i++) {
    analogWrite(LED, i);      // raise the voltage gradually from 0 - 255
                              // when you raise by 1, it means you raise the duty cyle by 1%
    delay(10);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(LED, i);     // decrease the voltage gradually from 255 - 0
    delay(10);
  }
}