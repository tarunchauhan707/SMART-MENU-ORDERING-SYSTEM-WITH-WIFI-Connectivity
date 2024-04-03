#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include<SoftwareSerial.h>
MCUFRIEND_kbv tft;
//defining LCD pins used
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
//define screen constansts
#define REDBAR_MINX 80
#define GREENBAR_MINX 130
#define BLUEBAR_MINX 180
#define BAR_MINY 30
#define BAR_HEIGHT 250
#define BAR_WIDTH 30
//touch screen working constants
#define MINPRESSURE 10
#define MAXPRESSURE 1000
#define TS_MINX 125
#define TS_MINY 85
#define TS_MAXX 965
#define TS_MAXY 905
//assigning message variable
const char *msg ;
SoftwareSerial s(1,0);


//Touch screen control pins
#define XP 8   //X-Plus
#define XM A2  //X-Minus
#define YP A3  //Y-Plus
#define YM 9   //Y-Minus
//declaring touchscreen variable and Initialising
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
//defining colors
#define BLACK    0x0000
#define BLUE     0x001F
#define DARKBLUE 0x0010
#define VIOLET   0x8888
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0
#define WHITE    0xFFFF
#define GREY   tft.color565(64, 64, 64);
#define GOLD     0xFEA0
#define BROWN    0xA145
#define SILVER   0xC618
#define LIME     0x07E0


//Menu Home Screen
void drawHome()
{
  //White background
  tft.fillScreen(WHITE);
  //Dish1* Box ===RICE
  tft.drawRoundRect(10, 30, 100, 80, 10, WHITE);
  tft.fillRoundRect(10, 30, 100, 80, 10, GOLD );
    //Dish2* BOX ===PANNER
  tft.drawRoundRect(130, 30, 100, 80, 10, WHITE);  
  tft.fillRoundRect(130, 30, 100, 80, 10, GOLD);
   //Dish3* Box
  tft.drawRoundRect(10, 120, 100, 80, 10, WHITE);
  tft.fillRoundRect(10, 120, 100, 80, 10, GOLD);
  //Dish4* Box
  tft.drawRoundRect(130, 120, 100, 80, 10, WHITE);  
  tft.fillRoundRect(130, 120, 100, 80, 10, GOLD);
  // //Call Waiter Box
  tft.drawRoundRect(10, 215, 220, 40, 10, WHITE);  
  tft.fillRoundRect(10, 215, 220, 40, 10, MAGENTA);
  //Water Box
  tft.drawRoundRect(10, 270, 220, 40, 10, WHITE);  
  tft.fillRoundRect(10, 270, 220, 40, 10, BLUE);
  //Menu Heading
  tft.setCursor(50, 0);
  tft.setTextSize(3);
  tft.setTextColor(LIME);
  tft.print("TABLE 07");
  ///
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
   //writing in dish1 box
  tft.setCursor(15, 60);
  tft.print(" RICE");
  //writing in dish2 box
  tft.setCursor(135, 60);
  tft.print(" PANNER");
  //writing in dish3 box
  tft.setCursor(20, 150);
  tft.print(" ROTI");
  //writing in dish6 box
  tft.setCursor(135, 150);
  tft.print(" RAJMA");
  //writing in bill box
  tft.setCursor(50, 225);
  tft.print(" Call Waiter");
  //writing water in water box
  tft.setCursor(95, 280);
  tft.print("Water");
  delay(500);
}


void Loading_Delay(){
   // Delay Box
  for (int i; i < 250; i++)
  {
    tft.fillRect(BAR_MINY - 10, BLUEBAR_MINX, i, 10, GREEN );
    delay(0.000000000000000000000000000000000000000000000001);
  }
}
void setup(void)
{
  Serial.begin(9600);
  tft.begin(0x9486);  
  tft.fillScreen(BLACK);
  tft.setRotation(0);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.setCursor(50, 140);
  tft.print("Loading...");
  tft.setTextColor(tft.color565(255, 255, 0));
  tft.setCursor(30, 70);
  tft.print("iRestaurant");
  tft.setCursor(15, 100);
  tft.print(" SMART MENU ");
  Loading_Delay();
  delay(500);


  // Loading Part.
  Serial.println(tft.readID(), HEX);
  tft.fillScreen(BLACK);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.setCursor(50, 140);
  tft.print("Loading...");


  // Calling function.
  Loading_Delay();
  delay(500);


  // Then become full sreen black.
  tft.fillScreen(BLACK);
  drawHome();
  Serial.println("Table 07");
}
//working main loop
void loop()
{
 TSPoint p = ts.getPoint();
  //the directions of the touchscreen pins
  pinMode(XP, OUTPUT);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(YM, OUTPUT);
  if (p.z > ts.pressureThreshhold)
    {
      p.x = map(p.x, TS_MAXX, TS_MINX, 0, 240);
      p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320); 
       if (p.x > 35 && p.x < 104 && p.y > 40 && p.y < 115 )
      {
        Serial.println("RICE Ordered");
        s.write("Dish1 Ordered");
        tft.fillRoundRect(10, 30, 100, 80, 10, WHITE);
        delay(70);
        tft.drawRoundRect(10, 30, 100, 80, 10, WHITE);
        tft.fillRoundRect(10, 30, 100, 80, 10, GOLD );
        tft.setCursor(15, 60);
        tft.print(" RICE");
        delay(70);
        }
         if (p.x > 158 && p.x < 224 && p.y > 45 && p.y < 110)
      {
        Serial.println("PANNER Ordered");
        s.write("PANNER Ordered");
        tft.fillRoundRect(130, 30, 100, 80, 10, WHITE);
        delay(70);
        tft.drawRoundRect(130, 30, 100, 80, 10, WHITE);  
        tft.fillRoundRect(130, 30, 100, 80, 10, GOLD);
        tft.setCursor(135, 60);
         tft.print(" PANNER");
        delay(70);
      }
      
      if (p.x > 32 && p.x < 108 && p.y > 134 && p.y < 192)
      {
        Serial.println("ROTI");
        s.write("ROTI Ordered");
        tft.fillRoundRect(10, 120, 100, 80, 10, WHITE);   //rgb led
        delay(70);
        tft.drawRoundRect(10, 120, 100, 80, 10, WHITE);
        tft.fillRoundRect(10, 120, 100, 80, 10, GOLD);  
        tft.setCursor(20, 150);
        tft.print(" ROTI");
        delay(70);  
      }
      
     
      if (p.x > 155 && p.x < 226 && p.y > 134 && p.y < 190)
      {
        Serial.println("RAJMA Ordered");
        s.write("RAJMA Ordered");
        tft.fillRoundRect(130, 120, 100, 80, 10, WHITE);
        delay(70);
        tft.drawRoundRect(130, 120, 100, 80, 10, WHITE);  
        tft.fillRoundRect(130, 120, 100, 80, 10, GOLD);
        tft.setCursor(135, 150);
        tft.print(" RAJMA");
        delay(70);
      }
      if (p.x > 38 && p.x < 217 && p.y > 237 && p.y < 252)
      {
        Serial.println("Call Waiter");
         s.write("Call Waiter");
        tft.fillRoundRect(10, 215, 220, 40, 8, WHITE);
        delay(70);
        tft.drawRoundRect(10, 215, 220, 40, 8, WHITE);  
        tft.fillRoundRect(10, 215, 220, 40, 8, MAGENTA);
        tft.setCursor(50, 225);
        tft.print(" Call Waiter");
        delay(70);
      }
      if (p.x > 36 && p.x < 209 && p.y > 280 && p.y < 308)
      {
        Serial.println("Water");
        s.write("Water");
        tft.fillRoundRect(10, 280, 220, 40, 8, WHITE);
        delay(70);
        tft.drawRoundRect(10, 270, 220, 40, 8, WHITE);  
        tft.fillRoundRect(10, 270, 220, 40, 8, BLUE);
        tft.setCursor(95, 280);
        tft.print("Water");
        delay(70);
      }
    }
}  
