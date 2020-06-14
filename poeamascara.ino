#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 7, 8, 9, 10, 11, 12);


byte mascara1[8] = {
	B01110,
	B10001,
	B11011,
	B10001,
	B11111,
	B11111,
	B01110,
	B00000
};

byte mascara2[8] = {
	B01110,
	B10001,
	B10001,
	B10001,
	B11111,
	B11111,
	B01110,
	B00000
};

byte alcool1[8] = {
	B01100,
	B01000,
	B11100,
	B10100,
	B10100,
	B10100,
	B10100,
	B11100
};
byte alcool2[8] = {
	B00000,
	B01101,
	B11100,
	B10100,
	B10100,
	B10100,
	B10100,
	B11100
};

int count = 0;

//variaveis do display
int backLight = 2; 
const int x_pin = A0;
const int y_pin = A1;
const int z_pin = A2;

//variavies do sensor de temperatura
const int SensorTemp = A4;
int TemperaturaC = 0;

// Volts per G-Force
const float sensitivity = 0.206;

void setup() {
  
  //variageis do beep
  pinMode(5, OUTPUT);
  
  
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); 
  lcd.begin(16,2);              
  lcd.clear();                  
  
  lcd.setCursor(0,0);           
  lcd.print(" Ola Sr. Sergio");
  delay(2000);
  lcd.clear(); 
  
  lcd.setCursor(0,0);
  lcd.print("   Bem vindo !");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("   Para a sua");
  lcd.setCursor(0,1);
  lcd.print("   Seguranca");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("    Fique em ");
  lcd.setCursor(0,1);
  lcd.print("      Casa");
  delay(2000);
  lcd.clear();
  
  analogReference(EXTERNAL);
  Serial.begin(9600);
}

void loop() {
  
  float x;
  float y;
  float z;

  // Read pins and convert to G
  x = (analogRead(x_pin) - 512) * 3.3 / (sensitivity * 1023);
  y = (analogRead(y_pin) - 512) * 3.3 / (sensitivity * 1023);
  z = (analogRead(z_pin) - 512) * 3.3 / (sensitivity * 1023);

  // Faz a leitura da tensao no Sensor de Temperatura
	int SensorTempTensao = analogRead(SensorTemp);
  
  if (count == 0) {
  	
    // ajusta a temperatura
    float TemperaturaC = map((SensorTempTensao - 31), 0, 542, -40, 125);

    // exibe a temperatura comportal
    lcd.clear();
    lcd.print("  Temperatura");
    lcd.setCursor(0,1);
    lcd.print("      C");
    lcd.setCursor(0,1);
  	lcd.print(TemperaturaC);
  	lcd.setCursor(9,1);
    noTone(5);
  }
  
  
  //botao de reset
  if (digitalRead(A5) == HIGH) {
  	count == 0;
   // noTone(5);
 	//lcd.clear();
  }
  
  //contador de passos
  if (x > 0) {
    count++;
  }
  Serial.println(count);
  
  // aviso "vibratorio", representado por beep e visual na tela do smartwatch
  if (count > 10) {
    
    lcd.setCursor(0,0);
  	lcd.print("Use a Mascara");
 	lcd.setCursor(0,1);
  	lcd.print("Alcool em gel");
    
  	lcd.createChar(1, mascara1);
  	lcd.setCursor(15, 0);  
  	lcd.write(byte(1));
  	delay(300);
  	lcd.createChar(1, mascara2);
  	lcd.setCursor(15, 0);  
  	lcd.write(byte(1));
  
  
  	lcd.createChar(0, alcool1);
  	lcd.setCursor(15, 1);  
  	lcd.write(byte(0));
  	delay(300);
  	lcd.createChar(0, alcool2);
  	lcd.setCursor(15, 1);  
  	lcd.write(byte(0));

  	tone(5, 440, 100);
  
  }
  
  
  
  
  
  // Display acceleration
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);

  delay(100);
}