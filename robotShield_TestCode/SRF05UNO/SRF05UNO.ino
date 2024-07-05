#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

const unsigned int TRIG_PIN=8;
const unsigned int ECHO_PIN=9;

char str[17];

long EchoTime;
int Dist;

void setup() {

  lcd.begin(2,16);
  lcd.print("   Distance    ");
  delay(1000);
  lcd.clear();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

void loop() {
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  EchoTime = pulseIn(ECHO_PIN, HIGH);
  Dist= EchoTime*0.034/2;
  lcd.setCursor(0,0);
  sprintf(str,"Distance : %3.0d",Dist);
  lcd.print(str);
}
