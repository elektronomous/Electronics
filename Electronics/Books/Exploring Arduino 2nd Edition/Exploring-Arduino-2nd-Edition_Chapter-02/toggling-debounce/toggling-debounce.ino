const int LED = 9;            // set the LED on PIN 9
const int BUTTON = 2;         // set the BUTTON on PIN 2

boolean lastButton = LOW;     // variable that containing the previous state
boolean currentButton = LOW;  // variable containing the current button state

boolean ledOn = false;        // The present of the LED on/off

void setup(void) {
  pinMode(LED, OUTPUT);       // set the LED PIN as OUTPUT
  pinMode(BUTTON, INPUT);     // set the BUTTON PIN as INPUT
}

/* 
 * Debouncing function
 * Pass it the previous button state,
 * and get back the current debounced button state.
 */
boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);    // Read the button state  
  if (last != current) {                    // if it is different
    delay(5);                       // wait for 5 ms..
    current = digitalRead(BUTTON);  // read it again
  } 
  return current;                   // return the current value
}

void loop(void) {
  currentButton = debounce(lastButton);     // Read debounced state 

  if (lastButton == LOW && currentButton == HIGH) {   // if it was pressed 
    ledOn = !ledOn;             // Toggle the LED value
  }
  lastButton = currentButton;   // Reset the button value
  digitalWrite(LED, ledOn);     // Change the LED state 
}