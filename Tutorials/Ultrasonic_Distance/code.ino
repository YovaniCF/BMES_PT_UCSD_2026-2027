const int trigPin = 10;
const int echoPin = 9;
const int greenLed = 3;  // Or other color
const int yellowLed = 4;
const int redLed = 5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
}

float readDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);      // 10 µs pulse starts a measurement
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);  // timeout ~5 m
  if (duration == 0) return 999;                  // nothing detected
  return duration * 0.0343 / 2;                   // sound speed, round trip
}

void loop() {
  float distance = readDistanceCm();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  digitalWrite(greenLed,  distance > 30);
  digitalWrite(yellowLed, distance <= 30 && distance > 15);
  digitalWrite(redLed,    distance <= 15);

  delay(100);
}
