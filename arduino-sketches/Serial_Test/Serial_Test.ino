int LED = 22;
//void setup() {
//  // initialize both serial ports:
//  Serial.begin(9600);
// pinMode(LED, OUTPUT);
////  Serial1.xbegin(9600);
//}
//
//void loop() {
//  // read from port 1, send to port 0:
//  if (Serial.available()>0) {
//    int inByte = Serial.read();
    
////    Serial.write(inByte);
//  }
//
//}

// Example 1 - Receiving single characters

char receivedChar;
boolean newData = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
    pinMode
}

void loop() {
    recvOneChar();
    showNewData();
}

void recvOneChar() {
    if (Serial.available() > 0) {
        receivedChar = Serial.read();
        newData = true;
        digitalWrite(LED, HIGH);
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChar);
        newData = false;
    }
}

