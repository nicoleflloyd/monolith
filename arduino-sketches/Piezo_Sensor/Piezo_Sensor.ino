const int panel1 = A0;
const int panel2 = A1;

//int panels = [panel1, panel2, panel3];
int num_pan = 3
int sensorReading1;
int sensorReading2;
int sensorReading3;


void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorReading1 = analogRead(panel1);
  sensorReading2 = analogRead(panel2);
  //Serial.println(sensorReading1);
  
  if(sensorReading1 > 10){
    Serial.println(1);
  }

  if(sensorReading2 >10){
    Serial.println(2);
  }

  
  delay(100);

}
