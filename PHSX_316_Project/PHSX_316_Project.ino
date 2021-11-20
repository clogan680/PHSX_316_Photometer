#include <LiquidCrystal.h>

int light;
float volts;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {

  light = analogRead(A0);
  volts = light * .0049;
  Serial.println(volts);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reading Volts");
  lcd.setCursor(0, 1);
  lcd.print("Value : ");
  lcd.setCursor(10, 1);
  lcd.print(volts);

  delay(300);

}
