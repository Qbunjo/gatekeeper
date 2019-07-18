#include <Wire.h>   
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27


void setup() {
     // ustawienia lcd
  lcd.begin(16, 2);
  // boot up
  pinMode (8, INPUT);
  pinMode (7, INPUT); 
}
// petla
void loop() {
  pinMode (8, INPUT);
  pinMode (7, INPUT);
  int stanBramy = digitalRead(8);
  int stanGarazu = digitalRead(7);
  //przygotuj wyswietlacz
  lcd.setCursor(0,0);
  lcd.print(" BRAMA");
  lcd.setCursor(0,1);
  lcd.print(" GARAZ");
     //wyswietl na pierwszym wierszu
  if (stanBramy == LOW)
  {
  lcd.setCursor(7, 0);
  lcd.print("OTWARTA    ");
   tone(10, 2500, 85);
   delay(85);
   tone (10,0,1);    
               delay(2000);
     }
  else
        lcd.setCursor(7, 0);
    lcd.print("ZAMKNIETA");
  
  //wyswietl na drugim wierszu
  if (stanGarazu == LOW)
  {
  lcd.setCursor(7,1);
  lcd.print("OTWARTY    ");
   tone(10, 2500, 85);
   delay(85);
   tone (10,0,1);    
               delay(2000);
     }
  else
    lcd.setCursor(7, 1);
    lcd.print("ZAMKNIETY");
  //if (stanBramy == LOW or stanGarazu == LOW);
  //{
  // tone(10, 2500, 85);
  // delay(85);
  // tone (10,0,1);    
  //        }
   //  delay(200);
  }
 
