/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 #define led_red  7
 #define led_yellow 6
 #define led_green 8
int vs = A0; // vibration sensor

void setup() {
  lcd.begin(16, 2);
  pinMode(led_red , OUTPUT);
  pinMode(led_yellow , OUTPUT);
  pinMode(led_green , OUTPUT);
  
  pinMode(vs, INPUT);
  
  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, LOW);
  lcd.setCursor(0,0 );
  lcd.print(" vibration :");
   
}

void loop() {
  long measurement =vibration();
  delay(50);
  int hz = measurement/1000;
  lcd.setCursor (0,1);
  lcd.print(hz);
 
  lcd.print("HZ            ");
  delay (100);
  
  
  if ((measurement > 0)&&(measurement < 4000)){
       digitalWrite(led_red, LOW);
       digitalWrite(led_yellow, LOW);
       digitalWrite(led_green, HIGH);
       delay(200);
  }
 
     else if ((measurement > 4000)&&(measurement < 16000)){
       digitalWrite(led_red, LOW);
       digitalWrite(led_yellow, HIGH);
       digitalWrite(led_green, LOW);
       delay(200);
  }
 
      else if (measurement > 16000){
        digitalWrite(led_red, HIGH);
        digitalWrite(led_yellow, LOW);
        digitalWrite(led_green, LOW);
        delay (200);
  }
  else{
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);
  }
  
}
long vibration(){
  long measurement=pulseIn (vs, HIGH); 
  return measurement;
  delay (50);
}

