#include <LiquidCrystal.h>

int light1;
int light2;

float volts1;
float volts2;

float pr_5549;
float pr_5506;

float R_fixed;
float V_supply;

float Current1;
float Current2;

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
  //  Serial.println(volts1);

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("LDR A0:");
  lcd.setCursor(10, 0);
  lcd.print(volts1);

  lcd.setCursor(2, 1);
  lcd.print("LDR A5:");
  lcd.setCursor(10, 1);
  lcd.print(volts2);

  delay(100);

}
