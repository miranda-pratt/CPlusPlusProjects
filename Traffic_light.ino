/*
 * In this program, there are three LEDS: a red LED, a yellow LED and a green LED. There is also a
 * buzzer and a switch. When the user presses the switch, the red LED lights up, followed by the yellow
 * and then the green where the buzzer sounds for one second and then stops until the user presses the switch again
 */

// Set variables
// Variable number = pin number
// All values except pinstatus are constants
const int GREEN = 8;
const int YELLOW = 10;
const int RED = 12;
const int buttonPin = 4;
const int buzzerPin = 6;
int pinstatus; // Variable to store the pin status of the button to determine whether the button has been pressed - this will change
// Set delay values for each light
const int DELAY_GREEN = 5000;
const int DELAY_YELLOW = 2000;
const int DELAY_RED = 5000;

// basic functions
void setup() {
  // Set the lights as outputs
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  // Set the button as input and the buzzer as an output
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop(){
  // Continually read the status of the button pin
  pinstatus = digitalRead(buttonPin);
  // If button is pressed start the sequence of lights
  if (pinstatus == HIGH) {
    // Display the red light
    red_light();
    // Wait a few seconds
    delay(DELAY_RED);
    // Display the yellow light
    yellow_light();
    // Wait a few seconds
    delay(DELAY_YELLOW);
    // Display the green light
    green_light();
  }
 
}

// Code for the green light
void green_light() {
  // Display only the green light and not the yellow or red lights
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  // Sound the buzzer for 1 second
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  // Turn off the buzzer
  digitalWrite(buzzerPin, LOW);
}

// Code for the yellow light
void yellow_light(){
  // Display only the yellow light and not the red or green lights
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}

// Code for the red_light
void red_light(){
  // Display only the red light and not the yellow or green lights
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}
