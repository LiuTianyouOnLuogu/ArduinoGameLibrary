#include <LiquidCrystal_I2C.h>
#indlude <Keypad.h>
#include "ArduinoGameLibrary.h"

LiquidCrystal_I2C lcd2004(ADD2004, 20, 4);
LiquidCrystal_I2C lcd1602(ADD1602, 16, 2);
Keypad keypad = Keypad(makeKeymap(keys), columns, rows, NUM_R, NUM_C);

void init(){
    lcd1602.init();
    lcd2004.init();
    Serial.init(115200);
}

char update_key(int delay_ms){
    delay(delay_ms);
    return keypad.getKey();
}

LiquidCrystal_I2C* LCD_type(LCD type){
    if(type == LCD2004){
        return &lcd2004;
    }else{
        return &lcd1602;
    }
}

void LCD_putchar(LCD type, byte x, byte y, char ch){
    LiquidCrystal_I2C* lcd = LCD_type(type);
    lcd -> setCursor(x, y);
    lcd -> print(ch);
}

void LCD_clear(LCD type){
    LiquidCrystal_I2C* lcd = LCD_type(type);
    lcd -> clear();
    lcd -> home();
}

void LCD_createChar(LCD type, byte no, byte* ch){
    LiquidCrystal_I2C* lcd = LCD_type(type);
    lcd -> createChar(no, ch);
}

void LCD_write(LCD type, byte x, byte y, char ch){
    LiquidCrystal_I2C* lcd = LCD_type(type);
    lcd -> setCursor(x, y);
    lcd -> write(no);
}