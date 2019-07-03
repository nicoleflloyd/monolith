#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 2
#define PIN2 3

int sensor1 = A13;
int sensor2 = A12 ;

int sensorReading1;
int sensorReading2;

bool sensorState1;
bool lastSensorState1;

bool sensorState2;
bool lastSensorState2;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(20, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(20, PIN2, NEO_GRB + NEO_KHZ800);


// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  Serial.begin(9600);
  strip1.begin();
  strip2.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.show(); // Initialize all pixels to 'off'
}

void loop() {

  sensorReading1 = analogRead(sensor1);
  sensorReading2 = analogRead(sensor2);
  
  Serial.print("Sensor 1 reading: ");
  Serial.println(sensorReading1);
  Serial.print("Sensor 2 reading: ");
  Serial.println(sensorReading2);

  if (sensorReading1 > 10) {
    sensorState1 = true;
  } else{
    sensorState1 = false;
  }

  if (sensorState1 != lastSensorState1){
    if (sensorState1){
      Serial.println("TAP1");
      // Some example procedures showing how to display to the pixels:
      colorWipe1(strip1.Color(255, 0, 0), 50); // Red    
      colorWipe1(strip1.Color(0, 255, 0), 50); // Green      
      colorWipe1(strip1.Color(0, 0, 255), 50); // Blue      
      colorWipe1(strip1.Color(0, 0, 0, 255), 50); // White RGBW
    
    }else{
      stripOff();
    }

    sensorState1 = lastSensorState1;
  }

//----------sensor2------//

  if (sensorReading2 > 50) {
    sensorState2 = true;
  } else{
    sensorState2 = false;
  }

  if (sensorState2 != lastSensorState2){
    if (sensorState2){
      Serial.println("TAP2");
      // Some example procedures showing how to display to the pixels:
      colorWipe2(strip2.Color(255, 0, 0), 50); // Red
      colorWipe2(strip2.Color(0, 255, 0), 50); // Green
      colorWipe2(strip2.Color(0, 0, 255), 50); // Blue
      colorWipe2(strip2.Color(0, 0, 0, 255), 50); // White RGBW

    }else{
      stripOff();
    }

    sensorState2 = lastSensorState2;
  }

  
}

// Fill the dots one after the other with a color
void colorWipe1(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(wait);
  }
}

void colorWipe2(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip2.setPixelColor(i, c);
    strip2.show();
    delay(wait);
  }
}

void stripOff(){
  Serial.println("OFF");
  
}


