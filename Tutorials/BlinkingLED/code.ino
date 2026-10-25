const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  // LED on
  delay(1000);                 // wait 1 second
  digitalWrite(ledPin, LOW);   // LED off
  delay(1000);
}
