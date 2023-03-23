#include <Arduino.h>
// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 64

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(25); // Set BRIGHTNESS to about 1/5 (max = 255)
}

// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<3; a++) {  // Repeat 3 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

void showAndDelete(int wait){
strip.show();
  delay(wait);
  strip.clear();
  strip.show();
}

void coloured_heart(uint32_t color, int wait){
  int heart[] = {10,11,13,14,16,17,18,19,20,21,22,25,26,27,28,29,30,31,33,34,35,36,37,43,44,45,51}; // heart
  strip.clear();
  strip.show();
  for(int b=0; b<2; b++){
    for(int i : heart) {
      strip.setPixelColor(i, color);
      //strip.show();
      //delay(wait);
    }
    delay(wait);
    showAndDelete(150);
  }
}


void allesIstGut(){
  int text_a[] = {1,2,3,4,10,11,12,13,14,17,18,20,21,22,25,26,29,30,33,34,35,36,37,38,41,42,45,46,49,50,53,54,57,58,61,62};
  int text_l[] = {5,6,9,10,21,22,25,26,37,38,41,42,45,46,49,50,51,52,53,54,57,58,59,60,61,62};
  int text_e[] = {1,2,3,4,5,9,10,11,12,13,14,21,22,25,26,27,28,29,34,35,36,37,38,41,42,49,50,51,52,53,54,58,59,60,61,62};
  int text_s[] = {1,2,3,4,5,9,10,11,12,13,14,21,22,25,26,27,28,29,33,34,35,36,37,45,46,49,50,51,52,53,54,57,58,59,60,61};
  int text_i[] = {2,3,4,5,10,11,12,13,20,19,27,28,35,36,43,44,50,51,52,53,58,59,60,61};
  int text_t[] = {1,2,3,4,5,6,9,10,11,12,13,14,20,19,27,28,35,36,43,44,51,52,59,60};
  int text_g[] = {2,3,4,5,9,10,11,13,14,17,18,21,22,25,26,33,34,35,37,38,41,42,45,46,49,50,51,52,53,54,58,59,60,61};
  int text_u[] = {1,2,5,6,9,10,13,14,17,18,21,22,25,26,29,30,33,34,37,38,41,42,45,46,49,50,51,52,53,54,58,59,60,61};
  int wait = 200;
// alles
  for(int i=0; i<64; i++) {
    strip.clear();
    strip.show();
  }

  for(int i : text_a) {
    strip.setPixelColor(i, strip.Color(155,   0,   0));
  }
  showAndDelete(400);

  for(int i : text_l) {
    strip.setPixelColor(i, strip.Color(255,   128,   0));
  }
  showAndDelete(400);

  for(int i : text_l) {
    strip.setPixelColor(i, strip.Color(255,   255,   0));
  }
  showAndDelete(400);

  for(int i : text_e) {
    strip.setPixelColor(i, strip.Color(0,   255,   0));
  }
  showAndDelete(400);

  for(int i : text_s) {
    strip.setPixelColor(i, strip.Color(0,   255,   128));
  }
  showAndDelete(400);

  // Herz
  coloured_heart(strip.Color(220,  0,   100), 120);

  // ist
 for(int i : text_i) {
    strip.setPixelColor(i, strip.Color(0,   255,   255));
  }
  showAndDelete(400);

   for(int i : text_s) {
    strip.setPixelColor(i, strip.Color(0,   128,   255));
  }
  showAndDelete(400);

   for(int i : text_t) {
    strip.setPixelColor(i, strip.Color(0,   0,   255));
  }
  showAndDelete(400);

  // Herz
  coloured_heart(strip.Color(220,  0,   100), 120);

  // gut
  for(int i : text_g) {
    strip.setPixelColor(i, strip.Color(128,   0,   255));
  }
  showAndDelete(400);

  for(int i : text_u) {
    strip.setPixelColor(i, strip.Color(255,   0,   255));
  }
  showAndDelete(400);
  for(int i : text_t) {
    strip.setPixelColor(i, strip.Color(255,   0,   128));
  }
  showAndDelete(400);

    // Herz
  coloured_heart(strip.Color(220,  0,   100), 120);
}


// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 1*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<3; a++) {  // Repeat 3 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}

void fireWork() {
  int stem1[] = {58};
  int stem2[] = {58,52};
  int stem3[] = {58,52,44};
  int stem4[] = {52,44,35};
  int ring1[] = {27,28,36,35};
  int ring2[] = {21,20,19,18,26,29,37,34,42,43,44,45};
  int ring3[] = {9,10,11,12,13,14,22,17,25,30,38,33,41,46,49,50,51,52,53,54};
  int ring4[] = {0,1,2,3,4,5,6,7,5,8,16,15,23,24,31,32,39,40,47,48,55,56,57,58,59,60,61,62,63};
  int r = 255;
  int b = 0;
  int g = 120;
  strip.clear();
  strip.show();
  for (int i : stem1) {
    strip.setPixelColor(i, strip.Color(r,b,g));
  }
  showAndDelete(200);

  for (int i : stem2) {
    strip.setPixelColor(i, strip.Color(r,b,g));
  }
  showAndDelete(200);

  for (int i : stem3) {
    strip.setPixelColor(i, strip.Color(r,b,g));
  }
  showAndDelete(200);

  for (int i : stem4) {
    strip.setPixelColor(i, strip.Color(r,b,g));
  }
  showAndDelete(200);

  for (int i : ring1) {
    strip.setPixelColor(i, strip.Color(r,b,g));
  }
  showAndDelete(200);

  for (int i : ring1) {
    strip.setPixelColor(i, strip.Color(100,   0,   120));
  }
  for (int i : ring2) {
    strip.setPixelColor(i, strip.Color(255,   0,   120));
  }
  showAndDelete(200);

  for (int i : ring1) {
    strip.setPixelColor(i, strip.Color(100,   100,   50));
  }
  for (int i : ring2) {
    strip.setPixelColor(i, strip.Color(100,   0,   120));
  }
  for (int i : ring3) {
    strip.setPixelColor(i, strip.Color(255,   0,   120));
  }
  showAndDelete(200);

  for (int i : ring1) {
    strip.setPixelColor(i, strip.Color(255,   255,   40));
  }
  for (int i : ring2) {
    strip.setPixelColor(i, strip.Color(100,   100,   50));
  }
  for (int i : ring3) {
    strip.setPixelColor(i, strip.Color(100,   0,   120));
  }
  for (int i : ring4) {
    strip.setPixelColor(i, strip.Color(255,   0,   120));
  }
  showAndDelete(200);

}

void pixelArt(){
  int Octo1[] = {3,4,10,11,12,13,17,18,19,20,21,22,24,25,27,28,30,31,32,33,34,35,36,37,38,39,42,45,49,51,52,54,56,58,61,63};
  int Octo2[] = {3,4,10,11,12,13,17,18,19,20,21,22,24,25,27,28,30,31,32,33,34,35,36,37,38,39,42,45,49,51,52,54,57,59,60,62};
  int Septo1[] = {9,13,21,20,19,25,26,27,28,29,34,36,38,41,42,43,44,45,49,51,53,55,56,58,60,62};
  int Septo2[] = {10,14,20,19,18,26,27,28,29,30,37,35,33,42,43,44,45,46,54,52,50,48,56,58,60,62};
  int Septo3[] = {10,14,20,19,18,26,27,28,29,30,37,35,33,42,43,44,45,46,54,52,50,48,57,59,61,63};
  int Septo4[] = {9,13,21,20,19,25,26,27,28,29,34,36,38,41,42,43,44,45,49,51,53,55,57,59,61,63};
  for(int b=0; b<3; b++){
    strip.clear();
    strip.show();
    for (int i : Octo1) {
      strip.setPixelColor(i, strip.Color(255,   125,   50));
    }
    strip.show();
    delay(400);
    strip.clear();
    strip.show();
    for (int i : Octo2) {
      strip.setPixelColor(i, strip.Color(255,   125,   50));
    }
    showAndDelete(400);
  }
  for(int b=0; b<2; b++){
    strip.clear();
    strip.show();
    for (int i : Septo1) {
      strip.setPixelColor(i, strip.Color(130,   50,   200));
    }
    strip.show();
    delay(400);
    strip.clear();
    strip.show();
    for (int i : Septo2) {
      strip.setPixelColor(i, strip.Color(130,   50,   200));
    }
    strip.show();
    delay(400);
    strip.clear();
    strip.show();
    for (int i : Septo3) {
      strip.setPixelColor(i, strip.Color(130,   50,   200));
    }
    strip.show();
    delay(400);
    strip.clear();
    strip.show();
    for (int i : Septo4) {
      strip.setPixelColor(i, strip.Color(130,   50,   200));
    }
    showAndDelete(400);
  }
  
}

void rambazamba() {
  int rambaRow1[] = {17,18,22,23,27,30,33,34,35,39,40,43,43,44,45,46,49,50,54,57,60,61,62,66,67,70}; // going down
  int rambaRow2[] = {15,12,10,7,5,3,2,0,-2,-5,-7,-10,-15,-17,-20,-22,-24,-25,-27,-29,-32,-34,-37,-39}; // going up
  int rambaRow3[] = {32,35,37,40,42,44,45,47,49,52,54,57,61,64,67,69,71,72,74,76,79,81,84,86}; // down
  int rambaRow4[] = {31,30,29,26,25,24,23,21,16,14,13,12,9,8,7,6,3,-1,-2,-3,-4,-6,-11,-13,-14,-15,-18,-19,-20,-21,-23}; // up
  int rambaRow5[] = {48,50,51,53,56,58,63,65,68,70,73,75,80,83,85,90,92,95,97,100,102}; // down
  int rambaRow6[] = {47,44,42,39,37,32,30,27,25,22,20,15,12,10,5,3,0,-2,-5}; // up
  int rambaRow7[] = {64,67,69,72,74,79,81,82,83,86,89,91,92,93,94,96,99,101,106,108,109,110,113,116,118}; // down

  // übergreifende schleife

  for(int b=0; b<63; b++) {    
    strip.clear();
    for (int i : rambaRow1) {
      if ((i - b) >= 8 && (i - b) <= 15) {
        strip.setPixelColor(i - b, strip.Color(130,   50,   200));
      }
    }
    for (int i : rambaRow3) {
      if ((i - b) >= 24 && (i - b) <= 31) {
        strip.setPixelColor(i - b, strip.Color(130,   50,   200));
      }
    }
    for (int i : rambaRow5) {
      if ((i - b) >= 40 && (i - b) <= 47) {
        strip.setPixelColor(i - b, strip.Color(130,   50,   200));
      }
    }
    for (int i : rambaRow7) {
      if ((i - b) >= 55 && (i - b) <= 63) {
        strip.setPixelColor(i - b, strip.Color(130,   50,   200));
      }
    }
    for (int i : rambaRow2) {
      if ((i + b) >= 16 && (i + b) <= 23) {
        strip.setPixelColor(i + b, strip.Color(130,   50,   200));
        }
    }
    for (int i : rambaRow4) {
      if ((i + b) >= 32 && (i + b) <= 39) {
        strip.setPixelColor(i + b, strip.Color(130,   50,   200));
        }
    }
    for (int i : rambaRow6) {
      if ((i + b) >= 48 && (i + b) <= 55) {
        strip.setPixelColor(i + b, strip.Color(130,   50,   200));
        }
    }
  strip.show();
  delay(100);
  }
}


// ----------------  loop() function -- runs repeatedly as long as board is on ---------------

void loop() {

  allesIstGut();
  rainbow(10);             // Flowing rainbow cycle along the whole strip
  theaterChaseRainbow(200); // Rainbow-enhanced theaterChase variant
  // rainbow(20);  
  coloured_heart(strip.Color(220,  0,   100), 150);
  // rambazamba();
  // rainbow(20);  
  pixelArt();
  fireWork();
  fireWork();
  
}
