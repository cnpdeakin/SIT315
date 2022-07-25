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
  pirStat = digitalRead(pirPin);
  if (pirStat == 1) {
    ledState = HIGH;
    digitalWrite(LED_BUILTIN, ledState);
  }
  else {
    ledState = LOW;
    digitalWrite(LED_BUILTIN, ledState);
  }
  
    Serial.println("SENSOR INPUT: "+ String(pirStat) +
               " || LED STATE: " + String(ledState));
  delay(1000); // Wait for 1000 millisecond(s)
}
