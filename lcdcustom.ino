
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
void setup() { 
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
   uint8_t bell[8] = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};
     uint8_t note[8] = {0x2,0x3,0x2,0xe,0x1e,0xc,0x0};
     uint8_t clock[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};
     uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
     uint8_t duck[8] = {0x0,0xc,0x1d,0xf,0xf,0x6,0x0};
     uint8_t check[8] = {0x0,0x1,0x3,0x16,0x1c,0x8,0x0};
     uint8_t cross[8] = {0x0,0x1b,0xe,0x4,0xe,0x1b,0x0};
     uint8_t retarrow[8] = { 0x1,0x1,0x5,0x9,0x1f,0x8,0x4};
     
     
     lcd.createChar(0, bell);
     lcd.createChar(1, note);
     lcd.createChar(2, clock);
     lcd.createChar(3, heart);
     lcd.createChar(4, duck);
     lcd.createChar(5, check);
     lcd.createChar(6, cross);
     lcd.createChar(7, retarrow);
     lcd.home();
     
}
void loop() { 
int i=0;
  lcd.clear();
   while (i<7) {
           lcd.setCursor(0,i);
           lcd.print("user:");
           for (int j=0; j<7; j++) {
                 lcd.print(j, HEX);
           }
           
           i++;
     }

}
