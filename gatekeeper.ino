
 
int prevGateSt = 0;// gate memory variable
  int prevGaragSt = 0; //garage memory variable
  int timer =0; //timer
int evClosed = 0; //all closed flag
// include the library code:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
     // lcd settings
  lcd.init();
  TurnOn();
  
  // boot up
  pinMode (8, INPUT);
  pinMode (7, INPUT);
  pinMode (10, OUTPUT);
  digitalWrite(10,HIGH);
//  Serial.begin(9600);
  //prepare lcd
  lcd.setCursor(0,0);
  lcd.print(" BRAMA  ");
  lcd.setCursor(0,1);
  lcd.print(" GARAZ");
}
void loop() {
  pinMode (8, INPUT);
  pinMode (7, INPUT);
  int curGateSt = digitalRead(8);
  int curGaragSt = digitalRead(7);
  if (curGateSt==0 && prevGateSt==1){
   TurnOn();}// if gate opens, turn on lcd
  if (curGaragSt==0 && prevGaragSt ==1){
    TurnOn();}// if garage opens, turn on lcd
    if (curGateSt == 1 && curGaragSt == 1){
    evClosed=1;}// if everything is closed, flag on
  else {evClosed=0;}
  if (evClosed==1) {
    timer++;}//if flag is on, count to lcd turnoff
  if (curGaragSt ==0) {
    timer=0;} //if garage opens, reset timer
  if (curGateSt ==0) {
    timer=0;} //if gate opens, reset timer
 // Serial.println(timer);//show timer in serial
  if (timer >=500){
    TurnOff();
  }//time to lcd turnoff
  if (curGateSt==0 && prevGateSt==1){
    TurnOn();}// if gate opens, turn on lcd
  if (curGaragSt==0 && prevGaragSt ==1){
   TurnOn();}// if garage opens, turn on lcd
     //print in the first row
  if (curGateSt == LOW)
  {
  lcd.setCursor(7, 0);
  lcd.print(" OTWARTA  ");
     }
  else
        lcd.setCursor(7, 0);
    lcd.print("ZAMKNIETA");
  
  //print in the second row
  if (curGaragSt == LOW)
  {
  lcd.setCursor(7,1);
  lcd.print(" OTWARTY    ");
     }
  else
    lcd.setCursor(7, 1);
    lcd.print("ZAMKNIETY");
  if (curGateSt == LOW || curGaragSt == LOW);
  {
   digitalWrite(10,HIGH);
  }
    prevGateSt=curGateSt; //remember previous state
    prevGaragSt=curGaragSt;
  if (timer==2000){
    timer=1;}//do not count to infinity
}
void TurnOn(){
  lcd.display();
  lcd.backlight();}
  void TurnOff(){
    lcd.noDisplay();
    lcd.noBacklight();
}
