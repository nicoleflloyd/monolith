#include <Adafruit_NeoPixel.h>

#define NUM_LIGHTS  4

int period = 300000;
int period2 = 100000;
unsigned long time_now = 0;

#define PIN1 12
#define PIN2 11
#define PIN3 10
#define PIN4 9
#define PIN5 6
#define PIN6 8
#define PIN7 7

#define PIN8 44
#define PIN9 46
#define PIN10 2
#define PIN11 3
#define PIN12 4
#define PIN13 5

int sensor1 = A9;
int sensor2 = A8;
int sensor3 = A7;
int sensor4 = A6;
int sensor5 = A5;
int sensor6 = A4;
int sensor7 = A2;
int sensor8 = A1;
int sensor9 = A3;
int sensor10 = A13;
int sensor11 = A12;
int sensor12 = A11;
int sensor13 = A10;

int sensorReading1;
int sensorReading2;
int sensorReading3;
int sensorReading4;
int sensorReading5;
int sensorReading6;
int sensorReading7;
int sensorReading8;
int sensorReading9;
int sensorReading10;
int sensorReading11;
int sensorReading12;
int sensorReading13;

int sensorState1;
int lastSensorState1;
int sensorState2;
int lastSensorState2;
int sensorState3;
int lastSensorState3;
int sensorState4;
int lastSensorState4;
int sensorState5;
int lastSensorState5;
int sensorState6;
int lastSensorState6;
int sensorState7;
int lastSensorState7;
int sensorState8;
int lastSensorState8;
int sensorState9;
int lastSensorState9;
int sensorState10;
int lastSensorState10;
int sensorState11;
int lastSensorState11;
int sensorState12;
int lastSensorState12;
int sensorState13;
int lastSensorState13;

int num1 = 13;
int num2 = 18;
int num3 = 6;
int num4 = 24;
int num5 = 8;
int num6 = 6;
int num7 = 11;
int num8 = 16;
int num9 = 15;
int num10 = 13;
int num11 = 15;
int num12 = 12;
int num13 = 18;



int brightness = 50;
int threshold = 1;
int startTimer;
int count=1;
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(13, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(18, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(6, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(24, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(8, PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(6, PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(11, PIN7, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(16, PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip9 = Adafruit_NeoPixel(15, PIN9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip10 = Adafruit_NeoPixel(13, PIN10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip11 = Adafruit_NeoPixel(15, PIN11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip12 = Adafruit_NeoPixel(12, PIN12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip13 = Adafruit_NeoPixel(18, PIN13, NEO_GRB + NEO_KHZ800);

uint32_t low1;
uint32_t high1;
uint32_t low2;
uint32_t high2;
uint32_t low3;
uint32_t high3;
uint32_t low4;
uint32_t high4; 
uint32_t low5;
uint32_t high5;
uint32_t low6;
uint32_t high6; 
uint32_t low7;
uint32_t high7;
uint32_t low8;
uint32_t high8; 
uint32_t low9;
uint32_t high9; 
uint32_t low10;
uint32_t high10;
uint32_t low11;
uint32_t high11; 
uint32_t low12;
uint32_t high12;
uint32_t low13;
uint32_t high13;

uint32_t change;
    

void setup() {
  Serial.begin(9600);

  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show();
  strip3.begin();
  strip3.show();
  strip4.begin();
  strip4.show();
  strip5.begin();
  strip5.show();
  strip6.begin();
  strip6.show();
  strip7.begin();
  strip7.show();

  strip8.begin();
  strip8.show(); 
  strip9.begin();
  strip9.show();
  strip10.begin();
  strip10.show();
  strip11.begin();
  strip11.show();
  strip12.begin();
  strip12.show();
  strip13.begin();
  strip13.show();
  
//clear out
  strip1.clear();
  strip2.clear();
  strip3.clear();
  strip4.clear();
  strip5.clear();
  strip6.clear();
  strip7.clear();
  strip8.clear();
  strip9.clear();
  strip10.clear();
  strip11.clear();
  strip12.clear();
  strip13.clear();

}

void loop() {
  sensorReading1 = analogRead(sensor1);
  sensorReading2 = analogRead(sensor2);
  sensorReading3 = analogRead(sensor3);
  sensorReading4 = analogRead(sensor4);
  sensorReading5 = analogRead(sensor5);
  sensorReading6 = analogRead(sensor6);
  sensorReading7 = analogRead(sensor7);
  sensorReading8 = analogRead(sensor8);
  sensorReading9 = analogRead(sensor9);
  sensorReading10 = analogRead(sensor10);
  sensorReading11 = analogRead(sensor11);
  sensorReading12 = analogRead(sensor12);
  sensorReading13 = analogRead(sensor13);


//  Serial.print("Sensor 1 reading: ");
//  Serial.println(sensorReading1);
//  Serial.print("Sensor 2 reading: ");
//  Serial.println(sensorReading2);
//  Serial.print("Sensor 3 reading: ");
//  Serial.println(sensorReading3);
//  Serial.print("Sensor 4 reading: ");
//  Serial.println(sensorReading4);
//  Serial.print("Sensor 5 reading: ");
//  Serial.println(sensorReading5);
//  Serial.print("Sensor 6 reading: ");
//  Serial.println(sensorReading6);
//  Serial.print("Sensor 7 reading: ");
//  Serial.println(sensorReading7);
//  Serial.print("Sensor 8 reading: ");
//  Serial.println(sensorReading8);
//  Serial.print("Sensor 9 reading: ");
//  Serial.println(sensorReading9);
//  Serial.print("Sensor 10 reading: ");
//  Serial.println(sensorReading10);
  
  low1 = strip1.Color(0, 0, 0); 
  high1 = strip1.Color(random(0,255), random(0,255), random(0,255)); 
  low2 = strip2.Color(0, 0, 0); 
  high2 = strip2.Color(random(0,255), random(0,255), random(0,255));
  low3 = strip3.Color(0, 0, 0); 
  high3 = strip3.Color(random(0,255), random(0,255), random(0,255)); 
  low4 = strip4.Color(0, 0, 0); 
  high4 = strip4.Color(random(0,255), random(0,255), random(0,255)); 
  low5 = strip5.Color(0, 0, 0); 
  high5 = strip5.Color(random(0,255), random(0,255), random(0,255)); 
  low6 = strip6.Color(0, 0, 0); 
  high6 = strip6.Color(random(0,255), random(0,255), random(0,255));  
  low7 = strip7.Color(0, 0, 0); 
  high7 = strip7.Color(random(0,255), random(0,255), random(0,255)); 
  low8 = strip8.Color(0, 0, 0); 
  high8 = strip8.Color(random(0,255), random(0,255), random(0,255));  
  low9 = strip9.Color(0, 0, 0); 
  high9 = strip9.Color(random(0,255), random(0,255), random(0,255)); 
  low10 = strip10.Color(0, 0, 0); 
  high10 = strip10.Color(random(0,255), random(0,255), random(0,255)); 
  low11 = strip11.Color(0, 0, 0); 
  high11 = strip11.Color(random(0,255), random(0,255), random(0,255)); 
  low12 = strip12.Color(0, 0, 0); 
  high12 = strip12.Color(random(0,255), random(0,255), random(0,255)); 
  low13 = strip13.Color(0, 0, 0); 
  high13 = strip13.Color(random(0,255), random(0,255), random(0,255)); 

  hits();

  //waits after 5 minutes to time out.
  if(millis() > time_now + period){
    time_now = millis();
    crazy();
  }

//  if(millis() > time_now + period2){
//        time_now = millis();
//        fades();
//  }
   
}


/////////////////////
void hits(){
  
  if(sensorReading1 >threshold){
 
    // Turn them off
    for( int i = 0; i<num1; i++){
        strip1.setPixelColor(i, high1);
        strip1.show();
    }   
    delay(100);
    
    for( int i = 0; i<num1; i++){
        strip1.setPixelColor(i, low1);
        strip1.show();
    } 
    delay(100);
    Serial.println("HIT,1");  
    }
     
  if(sensorReading2 >threshold){
 
    // Turn them off
    for( int i = 0; i<num2; i++){
        strip2.setPixelColor(i, high2);
        strip2.show();
    }   
    delay(100);
    
    for( int i = 0; i<num2; i++){
        strip2.setPixelColor(i, low2);
        strip2.show();
    } 
    delay(100);
    Serial.println("HIT,2");  
    }

if(sensorReading3 >threshold){
     
    // Turn them off
    for( int i = 0; i<num3; i++){
        strip3.setPixelColor(i, high3);
        strip3.show();
    }   
    delay(100);
    
    for( int i = 0; i<num3; i++){
        strip3.setPixelColor(i, low3);
        strip3.show();
    } 
    delay(100);
        Serial.println("HIT,3");  
  
    }

    if(sensorReading4 >threshold){
     
    // Turn them on
    for( int i = 0; i<num4; i++){
        strip4.setPixelColor(i, high4);
        strip4.show();
    }   
    delay(100);
    // Turn them off
    for( int i = 0; i<num4; i++){
        strip4.setPixelColor(i, low4);
        strip4.show();
    } 
    delay(100); 
        Serial.println("HIT,4");  
 
    }

      if(sensorReading5 >threshold){
   
    // Turn them off
    for( int i = 0; i<num5; i++){
        strip5.setPixelColor(i, high5);
        strip5.show();
    }   
    delay(100);
    
    for( int i = 0; i<num5; i++){
        strip5.setPixelColor(i, low5);
        strip5.show();
    } 
    delay(100); 
        Serial.println("HIT,5");  
 
    }

          if(sensorReading6 >threshold){
  
    // Turn them off
    for( int i = 0; i<num6; i++){
        strip6.setPixelColor(i, high6);
        strip6.show();
    }   
    delay(100);
    
    for( int i = 0; i<num6; i++){
        strip6.setPixelColor(i, low6);
        strip6.show();
    } 
    delay(100);
        Serial.println("HIT,6");  
  
    }

          if(sensorReading7 >threshold){
    
    // Turn them off
    for( int i = 0; i<num7; i++){
        strip7.setPixelColor(i, high7);
        strip7.show();
    }   
    delay(100);
    
    for( int i = 0; i<num7; i++){
        strip7.setPixelColor(i, low7);
        strip7.show();
    } 
    delay(100);
        Serial.println("HIT,7");  
  
    }


       if(sensorReading8 >threshold){
    
    // Turn them off
    for( int i = 0; i<num8; i++){
        strip8.setPixelColor(i, high8);
        strip8.show();
    }   
    delay(100);
    
    for( int i = 0; i<num8; i++){
        strip8.setPixelColor(i, low8);
        strip8.show();
    } 
    delay(100);
        Serial.println("HIT,8");  
  
    }


        if(sensorReading9 >threshold){
     
    // Turn them off
    for( int i = 0; i<num9; i++){
        strip9.setPixelColor(i, high9);
        strip9.show();
    }   
    delay(100);
    
    for( int i = 0; i<num9; i++){
        strip9.setPixelColor(i, low9);
        strip9.show();
    } 
    delay(100);
        Serial.println("HIT,9");  
  
    }

  if(sensorReading10 >threshold){
     
    // Turn them off
    for( int i = 0; i<num10; i++){
        strip10.setPixelColor(i, high10);
        strip10.show();
    }   
    delay(100);
    
    for( int i = 0; i<num10; i++){
        strip10.setPixelColor(i, low10);
        strip10.show();
    } 
    delay(100);
        Serial.println("HIT,10");  
  
    }


    
          if(sensorReading11 >threshold){
     
    // Turn them off
    for( int i = 0; i<num10; i++){
        strip11.setPixelColor(i, high11);
        strip11.show();
    }   
    delay(100);
    
    for( int i = 0; i<num11; i++){
        strip11.setPixelColor(i, low11);
        strip11.show();
    } 
    delay(100);
        Serial.println("HIT,11");  
  
    }



     if(sensorReading12 >threshold){
     
    // Turn them off
    for( int i = 0; i<num10; i++){
        strip12.setPixelColor(i, high12);
        strip12.show();
    }   
    delay(100);
    
    for( int i = 0; i<num12; i++){
        strip12.setPixelColor(i, low12);
        strip12.show();
    } 
    delay(100);
        Serial.println("HIT,12");  
  
    }



     if(sensorReading13 >threshold){
     
    // Turn them off
    for( int i = 0; i<num13; i++){
        strip13.setPixelColor(i, high13);
        strip13.show();
    }   
    delay(100);
    
    for( int i = 0; i<num13; i++){
        strip13.setPixelColor(i, low13);
        strip13.show();
    } 
    delay(100);
        Serial.println("HIT,13");  
  
    }
}

//////////////////////////
void fades(){
  
  for( int i = 0; i<num1; i++){
        strip1.setPixelColor(i, high1);
        strip1.show();
  }   
   
    for( int i = 0; i<num2; i++){
        strip2.setPixelColor(i, high2);
        strip2.show();
    }   
   
    for( int i = 0; i<num3; i++){
        strip3.setPixelColor(i, high3);
        strip3.show();
    }   
    
for( int i = 0; i<num4; i++){
        strip4.setPixelColor(i, high4);
        strip4.show();
    }   
    
 for( int i = 0; i<num5; i++){
        strip5.setPixelColor(i, high5);
        strip5.show();
    }   
    
    for( int i = 0; i<num6; i++){
        strip6.setPixelColor(i, high6);
        strip6.show();
    }   
   
 for( int i = 0; i<num7; i++){
        strip7.setPixelColor(i, high7);
        strip7.show();
    }   
    
for( int i = 0; i<num8; i++){
        strip8.setPixelColor(i, high8);
        strip8.show();
    }   
    
        for( int i = 0; i<num9; i++){
        strip9.setPixelColor(i, high9);
        strip9.show();
    }   
    
for( int i = 0; i<num10; i++){
        strip10.setPixelColor(i, high10);
        strip10.show();
    }   
    
    for( int i = 0; i<num10; i++){
        strip11.setPixelColor(i, high11);
        strip11.show();
    }   
    
    for( int i = 0; i<num10; i++){
        strip12.setPixelColor(i, high12);
        strip12.show();
    }   
   
    for( int i = 0; i<num13; i++){
        strip13.setPixelColor(i, high13);
        strip13.show();
    }    
  }

void crazy(){
  for( int i = 0; i<num1; i++){
        strip1.setPixelColor(i, high1);
        strip1.show();
  }   
   delay(100);
    
  for( int i = 0; i<num1; i++){
        strip1.setPixelColor(i, low1);
        strip1.show();
    } 
    delay(100);
    for( int i = 0; i<num2; i++){
        strip2.setPixelColor(i, high2);
        strip2.show();
    }   
    delay(100);
    
    for( int i = 0; i<num2; i++){
        strip2.setPixelColor(i, low2);
        strip2.show();
    } 
    delay(100);
    for( int i = 0; i<num3; i++){
        strip3.setPixelColor(i, high3);
        strip3.show();
    }   
    delay(100);
    
    for( int i = 0; i<num3; i++){
        strip3.setPixelColor(i, low3);
        strip3.show();
    } 
    delay(100);
for( int i = 0; i<num4; i++){
        strip4.setPixelColor(i, high4);
        strip4.show();
    }   
    delay(100);
    
    for( int i = 0; i<num4; i++){
        strip4.setPixelColor(i, low4);
        strip4.show();
    } 
    delay(100); 
 for( int i = 0; i<num5; i++){
        strip5.setPixelColor(i, high5);
        strip5.show();
    }   
    delay(100);
    
    for( int i = 0; i<num5; i++){
        strip5.setPixelColor(i, low5);
        strip5.show();
    } 
    delay(100); 
    for( int i = 0; i<num6; i++){
        strip6.setPixelColor(i, high6);
        strip6.show();
    }   
    delay(100);
    
    for( int i = 0; i<num6; i++){
        strip6.setPixelColor(i, low6);
        strip6.show();
    } 
    delay(100);
 for( int i = 0; i<num7; i++){
        strip7.setPixelColor(i, high7);
        strip7.show();
    }   
    delay(100);
    
    for( int i = 0; i<num7; i++){
        strip7.setPixelColor(i, low7);
        strip7.show();
    } 
    delay(100);
for( int i = 0; i<num8; i++){
        strip8.setPixelColor(i, high8);
        strip8.show();
    }   
    delay(100);
    
    for( int i = 0; i<num8; i++){
        strip8.setPixelColor(i, low8);
        strip8.show();
    } 
    delay(100);
        for( int i = 0; i<num9; i++){
        strip9.setPixelColor(i, high9);
        strip9.show();
    }   
    delay(100);
    
    for( int i = 0; i<num9; i++){
        strip9.setPixelColor(i, low9);
        strip9.show();
    } 
    delay(100);
for( int i = 0; i<num10; i++){
        strip10.setPixelColor(i, high10);
        strip10.show();
    }   
    delay(100);
    
    for( int i = 0; i<num10; i++){
        strip10.setPixelColor(i, low10);
        strip10.show();
    } 
    delay(100);
    for( int i = 0; i<num10; i++){
        strip11.setPixelColor(i, high11);
        strip11.show();
    }   
    delay(100);
    
    for( int i = 0; i<num11; i++){
        strip11.setPixelColor(i, low11);
        strip11.show();
    } 
    delay(100);
    for( int i = 0; i<num10; i++){
        strip12.setPixelColor(i, high12);
        strip12.show();
    }   
    delay(100);
    
    for( int i = 0; i<num12; i++){
        strip12.setPixelColor(i, low12);
        strip12.show();
    } 
    delay(100);
    for( int i = 0; i<num13; i++){
        strip13.setPixelColor(i, high13);
        strip13.show();
    }   
    delay(100);
    
    for( int i = 0; i<num13; i++){
        strip13.setPixelColor(i, low13);
        strip13.show();
    } 
    delay(100);
  }
