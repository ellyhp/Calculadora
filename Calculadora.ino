// Librería del teclado
#include <Keypad.h>

//libreria de la pantalla lcd
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);


const byte ROWS = 4; 
const byte COLS = 4;

// Mapeamos los botones en un arreglo
char hexaKeys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // Pines utilizados para las filas del teclado
byte colPins[COLS] = {6, 7, 8, 9}; // Pines utilizados para las columnas del teclado

// Inicializamos teclado
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);   // Inicializamos el monitor serial

  //inicializamos pantalla lcd
  lcd.init();
  lcd.backlight();
}

void loop() {

  // Lee cuando presionas el botón
  char button = customKeypad.getKey();

  if (button) {
    Serial.println(button);

    lcd.clear(); // Limpiamos la pantalla en cada iteración del bucle
    lcd.setCursor(6, 1); // Posición del cursor para centrar "Hola mundo"
    lcd.print(button);
  }


   
}
