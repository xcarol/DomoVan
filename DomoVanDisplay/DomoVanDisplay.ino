// DomoVan utilitza un display mcufriend 2.4 TFT LCD ToushScreen
// per poder-nos-hi comunicar necessitem les llibreries que s'indiquen a sota
// i que hem de copiar al director .../arduino/libraries
//
// http://www.instructables.com/id/UNO-R3-28-TFT-Touch-Screen-With-SD-Card-Socket-for/
// https://github.com/adafruit/Adafruit-GFX-Library
// https://github.com/adafruit/TFTLCD-Library
// https://github.com/adafruit/Touch-Screen-Library/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//Posem en marxa les comunicacions amb el Serial per a pode mostrar missatge per la consola
//Eines -> Monitor sèrie. Si el flag waitSerial està a true esperarà a que connectem la consola
//per continuar. Si està a false no s'espera.
void setupSerial()
{
  bool waitSerial = false;
  
  Serial.begin(9600);
  
  while (waitSerial && !Serial) {
    // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println(F("DomoVan en marxa!"));
}

void setupDisplay()
{
  //Els exemples no idenificaven el display, però en el README.txt de la llibreria TFTLCD 
  //diu ili9341(2.4inch 240x320) i de l'exemple graphicstest deduim que es el 0x9341
  uint16_t identifier = 0x9341;
  tft.reset();
  tft.begin(identifier);

  tft.setRotation(1);
  
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);  
  tft.setTextSize(2);

  tft.setCursor(0, 0);
  tft.println("Hola soc la DomoVan!");
}

void setup() {
  setupSerial();
  setupDisplay();
}

void loop() {
}


