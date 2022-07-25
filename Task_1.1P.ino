// C++ code
//

int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                // PIR status
int ledState = LOW;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  //read input of PIR
  pirStat = digitalRead(pirPin);
  
  //If PIR detected motion, LED is lit. Else if PIR does not detect motion, LED is OFF.
  if (pirStat == 1) {
    ledState = HIGH;
    digitalWrite(LED_BUILTIN, ledState);
  }
  else {
    ledState = LOW;
    digitalWrite(LED_BUILTIN, ledState);
  }
  
  //print sensor and led state to serial monitor
  Serial.println("SENSOR INPUT: "+ String(pirStat) +
                 " || LED STATE: " + String(ledState));
  
  // Wait for 1000 millisecond(s)
  delay(1000); 
}
