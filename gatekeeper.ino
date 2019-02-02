// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // lcd settings
  lcd.begin(16, 2);
  // boot up
  pinMode (8, INPUT);
  pinMode (7, INPUT);
}

// loop
void loop() {
  pinMode (8, INPUT);
  pinMode (7, INPUT);
  int stanBramy = digitalRead(8);
  int stanGarazu = digitalRead(7);
  //prepare lcd
  lcd.setCursor(0,0);
  lcd.print(" GATE");
  lcd.setCursor(0,1);
  lcd.print(" GARAGE");
  //print in the first row
  if (stanBramy == LOW) {
    lcd.setCursor(7, 0);
    lcd.print("OPEN    ");
  } else {
    lcd.setCursor(7, 0);
    lcd.print("CLOSED");
  }
  //print in the second row
  if (stanGarazu == LOW)
  {
    lcd.setCursor(7,1);
    lcd.print("OPEN    ");
  } else {
    lcd.setCursor(7, 1);
    lcd.print("CLOSED");
  }
  //make a beep
  if (stanBramy == LOW || stanGarazu == LOW) {
    tone(10, 2500, 85);
    delay(85);
    tone (10,0,1);
  }
  delay(2000);
}
