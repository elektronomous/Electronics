const int BLED = 9;       // BLUE LED Cathode on PIN 9
const int GLED = 10;      // GREEN LED Cathode on PIN 10
const int RLED = 11;      // RED LED Cathode on PIN 11
const int BUTTON = 2;     // The BUTTON is connected to PIN 2

boolean lastButton = LOW;     // Last Button State
boolean currentButton = LOW;  // Current Button State
int ledMode = 0;              // Cycle between LED states 

/*
 * Debouncing Function
 * Pass it the previous button state,
 * and get back the current debounced button state
*/

boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);    // Read the currently button state

  if (last != current) {            // if the button was PRESS, then this will be different
    delay(5);                       // so delay for 5ms 
    current = digitalRead(BUTTON);  // we read again so we get the fix state of the button
  }

  return current;
}

/*
 * LED Mode Selection
 * Pass a number for the LED state and set it accordingly
 * (mengoper sebuah angka sebagai indikator LEDnya dan menyalakan LED sesuai dengan angka itu)
 * NOTE: since the RGB LED is COMMON ANODE, you must set the cathode pin for each color LOW
 *       that color to turn ON.
*/

void setMode(int mode) {
  // RED 
  if (mode == 1)
    dSetStates(HIGH, LOW, LOW);
  
  // GREEN
  else if (mode == 2) 
    dSetStates(LOW, HIGH, LOW);
  
  // BLUE 
  else if (mode == 3)
    dSetStates(LOW, LOW, HIGH);
  
  // PURPLE(RED + BLUE)
  else if (mode == 4)
    aSetStates(128, 0, 128);
  
  // TEAL (BLUE + GREEN)
  else if (mode == 5)
    aSetStates(0, 128, 128);
  
  // ORANGE (GREEN + RED)
  else if (mode == 6)
    aSetStates(255, 69, 0);
  
  // WHITE (GREEN + RED + BLUE)
  else if (mode == 7)
    aSetStates(255, 255, 255);
  
  // OFF (Mode 0)
  else 
    dSetStates(LOW, LOW, LOW);
}


/*
 * LED dSetStates
 * Pass the three states of the LED start from RLED -> GLED -> BLED
 * so you dont have to write digitalWrite() function many times 
*/
void dSetStates(boolean state1, boolean state2, boolean state3) {
  digitalWrite(RLED, state1);
  digitalWrite(GLED, state2);
  digitalWrite(BLED, state3);
}

/*
 * LED aSetStates
 * Pass the three states of the LED start from RLED -> GLED -> BLED
 * so you dont have to write analogWrite() function many times 
*/
void aSetStates(int state1, int state2, int state3) {
  analogWrite(RLED, state1);
  analogWrite(GLED, state2);
  analogWrite(BLED, state3);
}

void setup(void) {
  pinMode(BLED, OUTPUT);    // Set BLUE LED as OUTPUT
  pinMode(GLED, OUTPUT);    // Set GREEN LED as OUTPUT
  pinMode(RLED, OUTPUT);    // Set RED LED as OUTPUT
}

void loop(void) {
  currentButton = debounce(lastButton);     // Read debounced state

  if (lastButton == LOW && currentButton == HIGH)   // If it was pressed
    ledMode++;
  
  lastButton = currentButton;

  // If you've cycled through the different options,
  // reset the counter to 0
  if (ledMode == 8) ledMode = 0;
  setMode(ledMode);                 // Change the LED state
}