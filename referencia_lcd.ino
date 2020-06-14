/* ------------------------------------------------------------------------------- */
// character LCD example code
// www.hacktronics.com

#include <LiquidCrystal.h>

// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

int backLight = 13;    // pin 13 will control the backlight

void setup()
{
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  
    
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Hola, Testing");    // change text to whatever you like. keep it clean!
  lcd.setCursor(0,1);           // set cursor to column 0, row 1
  lcd.print("arduino lcd  ");
  
  lcd.createChar(0, smiley);
  lcd.setCursor(15, 1);  
  lcd.write(byte(0));
  
  // inicializa la comunicación serial en 9600 bits por segundo
  Serial.begin(9600);
  
  
}

void loop()
{
  delay(1000);
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  
  // lee la entrada analógica desde el pin 0
  int valor_sensor = analogRead(A0);
  // muestra el valor que se leyó
  Serial.println(valor_sensor);
  delay(1);        // retraso entre lectura y lectura, para la estabilidad
}