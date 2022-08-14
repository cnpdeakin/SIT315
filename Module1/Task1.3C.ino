// C++ code

int pirPin1 = 2;                // PIR1 Out pin
int pirPin2 = 3; 				// PIR2 Out pin
int ledState = LOW;				// LED state


//initialise pins, serial monitor & setup interrupt for pirPin
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin1, INPUT_PULLUP);
  pinMode(pirPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), toggleLED, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), toggleLED, CHANGE);
  Serial.begin(9600);
}

void loop()
{
  delay(1000); // Wait for 1000 millisecond(s)
}

//Function will be toggled when motion is detected changes state
void toggleLED()
{
  int pirStat1 = digitalRead(pirPin1);
  int pirStat2 = digitalRead(pirPin2); 
  
  ledState = !ledState;
 
  digitalWrite(LED_BUILTIN, ledState);
  
  //Print sensor and LED state to serial monitor
  Serial.println("SENSOR 1 INPUT: "+ String(pirStat1) +
                 " || SENSOR 2 INPUT: " + String(pirStat2) +
               " || LED STATE: " + String(ledState));
}
