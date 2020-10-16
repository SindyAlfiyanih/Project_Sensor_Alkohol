#include <LiquidCrystal.h>
LiquidCrystal lcd(13 ,12 ,11 ,10 ,9, 8);

int GAS_SENSOR_LOW= 3;
int GREEN_LED = 4;
int BLUE_LED = 5;

void setup () {
    pinMode(GAS_SENSOR_LOW, INPUT);
    pinMode(GREEN_LED,OUTPUT);
    pinMode(BLUE_LED,OUTPUT);

    lcd.begin (20,4);
    lcd.setCursor (0,0);
    lcd.print("SISTEM PENDETEKSI");
    lcd.setCursor(0,1);
    lcd.print("SENSOR ALKOHOL");
    lcd.setCursor (0,2);
    lcd.print ("TELEKOMUNIASI PNJ");

    delay (1000);
}
void loop() {
  
  int GAS_SENSOR_LOW_READ = digitalRead(GAS_SENSOR_LOW);
  if (GAS_SENSOR_LOW_READ == LOW)
{
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALKOHOL TERDETEKSI");
    lcd.setCursor(0,3);
    lcd.print("BERBAHAYA");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    delay (20);
} 
  else 
{
   lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALKOHOL TIDAK");
    lcd.setCursor(0,2);
    lcd.print("TERDETEKSI");
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    delay (20);
  }
}
