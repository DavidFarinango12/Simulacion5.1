/*
 *CAPITULO V: FUNCIONES ESPECIFICAS
 *CODIGO 19: LECTURA Y ESCRITURA DE DATOS EN LA MEMRIA EEPROM
 *OBJETIVO: ALMACENAR UN VALOR DEL NUESTRA ENTRADA ANALOGICA SISE ENCUENTRA DENTRO DE UN RANGO ESTABLECIDO 
 *NOMBRE: RAFAEL FARINANGO
 *FUNCIONES:  EEPROM.write(dir,valor);
 *            EEPROM.read(dir);
 *            EEPROM.update(dir,valor); actualiza el valor, si ya tiene valor no hace cambios
 */

#include <EEPROM.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
int i = 0;
int valor_cad;
int val_max; 
int val_min;

 
void setup() {
  lcd.begin(16,2);
  valor_cad = EEPROM.read(0);     //lee valor en esa posicion
  val_max = valor_cad + 5;      //rango de error max
  val_min = valor_cad - 5;      //rango error min
}

void loop() {
  if((analogRead(A0)/4) > val_max || (analogRead(A0)/4) < val_min){
    valor_cad = analogRead(A0)/4;
    EEPROM.write(0,valor_cad);        // escibe datos en la memoria
    val_max = valor_cad + 5;
    val_min = valor_cad - 5;
  }
  lcd.setCursor(0,0);
  lcd.print(String("Memoria: ")+String(valor_cad));
  lcd.setCursor(0,1);
  lcd.print(String("CAD: ")+String(analogRead(A0)/4));
  delay(500);
  lcd.clear();
}
