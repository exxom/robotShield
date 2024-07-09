#include "sensor.h"

#include <LiquidCrystal.h>

LDR LDRsens1(A0);
LDR LDRsens2(A1);
LDR LDRsens3(A2);

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); 
char str[17];

void setup() {
  lcd.begin(16,2);
  lcd.print("  Ligth Sensor  ");
  delay(1000);
  lcd.clear();

}

void loop() {
  LDRsens1.Brightness();
  LDRsens2.Brightness();
  LDRsens3.Brightness();
  lcd.setCursor(0, 0);
  uint16_t average= LDR::Avrage();
  lcd.println( average);

}