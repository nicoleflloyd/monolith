#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

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


int brightness = 50;
int threshold = 25;
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
Adafruit_NeoPixel strip9 = Adafruit_NeoPixel(12, PIN9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip10 = Adafruit_NeoPixel(13, PIN10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip11 = Adafruit_NeoPixel(15, PIN11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip12 = Adafruit_NeoPixel(12, PIN12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip13 = Adafruit_NeoPixel(18, PIN13, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
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
  strip8.show(); // Initialize all pixels to 'off'
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
}

void loop(){}


