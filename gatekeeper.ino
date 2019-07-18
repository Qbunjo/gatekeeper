int prevGateSt = 0;// gate memory variable
  int prevGaragSt = 0; //garage memory variable
  int timer =0; //timer
int evClosed = 0; //all closed flag
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
     // lcd settings
  lcd.begin(16, 2);
  lcd.display();
  // boot up
  pinMode (8, INPUT);
  pinMode (7, INPUT);
  pinMode (10, OUTPUT);
  digitalWrite(10,HIGH);
  Serial.begin(9600);
  //prepare lcd
  lcd.setCursor(0,0);
  lcd.print(" GATE  ");
  lcd.setCursor(0,1);
  lcd.print(" GARAGE");
}
void loop() {
  pinMode (8, INPUT);
  pinMode (7, INPUT);
  int curGateSt = digitalRead(8);
  int curGaragSt = digitalRead(7);
  if (curGateSt==0 && prevGateSt==1){
    lcd.display();}// if gate opens, turn on lcd
  if (curGaragSt==0 && prevGaragSt ==1){
    lcd.display();}// if garage opens, turn on lcd
    if (curGateSt == 1 && curGaragSt == 1){
    evClosed=1;}// if everything is closed, flag on
  else {evClosed=0;}
  if (evClosed==1) {
    timer++;}//if flag is on, count to lcd turnoff
  if (curGaragSt ==0) {
    timer=0;} //if garage opens, reset timer
  if (curGateSt ==0) {
    timer=0;} //if gate opens, reset timer
  Serial.println(timer);//show timer in serial
  if (timer >=25){
    lcd.noDisplay();}//time to lcd turnoff
  if (curGateSt==0 && prevGateSt==1){
    lcd.display();}// if gate opens, turn on lcd
  if (curGaragSt==0 && prevGaragSt ==1){
    lcd.display();}// if garage opens, turn on lcd
     //print in the first row
  if (curGateSt == LOW)
  {
  lcd.setCursor(7, 0);
  lcd.print("  OPEN  ");
     }
  else
        lcd.setCursor(7, 0);
    lcd.print("  CLOSED");
  
  //print in the second row
  if (curGaragSt == LOW)
  {
  lcd.setCursor(7,1);
  lcd.print("  OPEN    ");
     }
  else
    lcd.setCursor(7, 1);
    lcd.print("  CLOSED");
  if (curGateSt == LOW || curGaragSt == LOW);
  {
   digitalWrite(10,HIGH);
  }
    prevGateSt=curGateSt; //remember previous state
    prevGaragSt=curGaragSt;
  if (timer==500){
    timer=1;}//do not count to infinity
}
