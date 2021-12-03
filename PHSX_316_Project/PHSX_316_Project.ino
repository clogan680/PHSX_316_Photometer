#include <LiquidCrystal.h>

int light1;
int light2;

float volts1;
float volts2;

float pr_5549;
float pr_5506;

float r_fixed = 10000;
float v_supply_5 = 5;
float v_supply_3_3 = 3.333;

float current1;
float current2;

float power1;
float power2;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {

  light1 = analogRead(A0);
  light2 = analogRead(A5);

  volts1 = light1 * .0049;
  volts2 = light2 * .0049;

  pr_5549 = v_supply_5 * r_fixed / volts1 - r_fixed;
  pr_5506 = v_supply_3_3 * r_fixed / volts2 - r_fixed;

  current1 = volts1 / pr_5549;
  current2 = volts2 / pr_5506;

  power1 = volts1 * current1;
  power2 = volts2 * current2;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Watts1:");
  lcd.setCursor(8, 0);
  lcd.print(power1, 6);

  lcd.setCursor(0, 1);
  lcd.print("Watts2:");
  lcd.setCursor(8, 1);
  lcd.print(power2, 6);

  delay(100);

}
