#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#define PIN1 11
//#define PIN2 10
//#define PIN3 9
//#define PIN4 8
//#define PIN5 2
//#define PIN6 3
//#define PIN7 4
//#define PIN8 5
//#define PIN9 6
//#define PIN10 7
//#define PIN11 12
//#define PIN12 46
//#define PIN13 44

int j=20;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(10, PIN1, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(10, PIN2, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(13, PIN3, NEO_GRB + NEO_KHZ800); //A//0
//Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(18, PIN4, NEO_GRB + NEO_KHZ800); //B//1
//Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(6, PIN5, NEO_GRB + NEO_KHZ800); //C//2
//Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(24, PIN6, NEO_GRB + NEO_KHZ800); //D//3
//Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(8, PIN7, NEO_GRB + NEO_KHZ800); //E//4
//Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(20, PIN8, NEO_GRB + NEO_KHZ800); //F//5
//Adafruit_NeoPixel strip9 = Adafruit_NeoPixel(20, PIN9, NEO_GRB + NEO_KHZ800); //E//6
//Adafruit_NeoPixel strip10 = Adafruit_NeoPixel(20, PIN10, NEO_GRB + NEO_KHZ800); //G//7
//Adafruit_NeoPixel strip11 = Adafruit_NeoPixel(20, PIN11, NEO_GRB + NEO_KHZ800); //H//8
//Adafruit_NeoPixel strip12 = Adafruit_NeoPixel(20, PIN12, NEO_GRB + NEO_KHZ800); //I//9
//Adafruit_NeoPixel strip13 = Adafruit_NeoPixel(20, PIN13, NEO_GRB + NEO_KHZ800); //J//10


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


  strip1.begin();
//  strip2.begin();
//  strip3.begin();
//  strip4.begin();
//  strip5.begin();
//  strip6.begin();
//  strip7.begin();
//  strip8.begin();
//  strip9.begin();
//  strip10.begin();
//  strip11.begin();
//  strip12.begin();
//  strip13.begin();

  strip1.show(); // Initialize all pixels to 'off'
//  strip2.show(); // Initialize all pixels to 'off'
//  strip3.show(); // Initialize all pixels to 'off'
//  strip4.show(); // Initialize all pixels to 'off'
//  strip5.show(); // Initialize all pixels to 'off'
//  strip6.show(); // Initialize all pixels to 'off'
//  strip7.show(); // Initialize all pixels to 'off'
//  strip8.show(); // Initialize all pixels to 'off'
//  strip9.show(); // Initialize all pixels to 'off'
//  strip10.show(); // Initialize all pixels to 'off'
//  strip11.show(); // Initialize all pixels to 'off'
//  strip12.show(); // Initialize all pixels to 'off'
//  strip13.show(); // Initialize all pixels to 'off'
}

void loop() {
    strip1.setPixelColor(10, 255, 255, 255);
//  strip2.setPixelColor(j, 255, 255, 255);
//  strip3.setPixelColor(j, 255, 255, 255);
//  strip4.setPixelColor(j, 255, 255, 255);
//  strip5.setPixelColor(j, 255, 255, 255);
//  strip6.setPixelColor(j, 255, 255, 255);
//  strip7.setPixelColor(j, 255, 255, 255);
//  strip8.setPixelColor(j, 255, 255, 255);
//  strip9.setPixelColor(j, 255, 255, 255);
//  strip10.setPixelColor(j, 255, 255, 255);
//  strip11.setPixelColor(j, 255, 255, 255);
//  strip12.setPixelColor(j, 255, 255, 255);
//  strip13.setPixelColor(j, 255, 255, 255);
  strip1.show(); // Initialize all pixels to 'off'
//  strip2.show(); // Initialize all pixels to 'off'
//  strip3.show(); // Initialize all pixels to 'off'
//  strip4.show(); // Initialize all pixels to 'off'
//  strip5.show(); // Initialize all pixels to 'off'
//  strip6.show(); // Initialize all pixels to 'off'
//  strip7.show(); // Initialize all pixels to 'off'
//  strip8.show(); // Initialize all pixels to 'off'
//  strip9.show(); // Initialize all pixels to 'off'
//  strip10.show(); // Initialize all pixels to 'off'
//  strip11.show(); // Initialize all pixels to 'off'
//  strip12.show(); // Initialize all pixels to 'off'
//  strip13.show(); // Initialize all pixels to 'off'
}





