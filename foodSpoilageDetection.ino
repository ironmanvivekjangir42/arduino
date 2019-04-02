#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int sensor1=0,sensor2=0,sensor3=0,sensor4=0;

void setup()   {          
  pinMode(10, OUTPUT);     
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  // draw a single pixel
  display.drawPixel(10, 10, WHITE);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {  
    sensor1=analogRead(0)/10;
    sensor2=analogRead(1)/10;
    sensor3=analogRead(2)/10;
    sensor4=analogRead(3)/10;
    Serial.println(sensor1);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(10,0);
    display.clearDisplay();
    display.invertDisplay(false);
    display.print("gas1 ");
    display.print(sensor1);
    display.println(" %");
    display.print("gas2 ");
    display.print(sensor2);
    display.println(" %");
    display.print("  gas3 ");
    display.print(sensor3);
    display.println(" %");
    display.print("gas4 ");
    display.print(sensor4);
    display.print(" %");
    display.display();
    delay(200);
    display.clearDisplay();
    if (sensor1>40 ||sensor2<20|| sensor3>460|| sensor4>30)
    {
      digitalWrite(10,HIGH);
      delay(500);
      digitalWrite(10,LOW);
    }
}


