// C++ code

int soilPin = A0;				// Soil Out pin
int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                // PIR status
int ledState = LOW;				// LED state


//initialise pins, serial monitor & setup interrupt for pirPin
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin, INPUT_PULLUP);
  pinMode(soilPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), toggleLED, CHANGE);
  Serial.begin(9600);
}

void loop()
{
  //reads the soil pin and outputs the value to the serial every second
  float soilReading = analogRead(soilPin);
  Serial.println("Soil Reading: " + String(soilReading));
  delay(1000); // Wait for 1000 millisecond(s)
}

//Function will be toggled when pin 2 (pirPIN) changes state
void toggleLED()
{
  ledState = !ledState;
  pirStat = !pirStat;
  digitalWrite(LED_BUILTIN, ledState);
  
  //Print sensor and LED state to serial monitor
  Serial.println("SENSOR INPUT: "+ String(pirStat) +
               " || LED STATE: " + String(ledState));
}
