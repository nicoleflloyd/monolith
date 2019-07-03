int outputPin = 13;
int knockSensor = A13;

int sensorReading;


void setup() {
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorReading = analogRead(knockSensor);
  Serial.println(sensorReading);
  delay(100);

}
