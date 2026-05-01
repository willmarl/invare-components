#include <LiquidCrystal.h>

// LCD pin connections
#define RS 12
#define EN 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // 16 columns, 2 rows
  
  lcd.print("Hello World!");
  lcd.setCursor(0, 1);  // Row 2
  lcd.print("LCD1602 Works!");
}

void loop() {
  delay(1000);
  lcd.clear();
  
  lcd.print("Count: ");
  for (int i = 0; i <= 9; i++) {
    lcd.print(i);
    delay(500);
  }
}