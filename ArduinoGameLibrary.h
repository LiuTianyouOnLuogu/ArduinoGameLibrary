#pragma once

#define ADD2004 0xA0
#define ADD1602 0xA1
enum LCD{LCD2004, LCD1602};

#define NUM_C 4
#define C1 25
#define C2 24
#define C3 23
#define C4 22

#define NUM_R 4
#define R1 26
#define R2 27
#define R3 28
#define R4 29

const byte columns[NUM_C] = {C1, C2, C3, C4};
const byte rows[NUM_R] = {R1, R2, R3, R4};
const char keys[NUM_C][NUM_R] ={
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'E', '0', 'F', 'D'}
};

#define SPEAKER_PIN 11

void init();
char update_key(int);
LiquidCrystal_I2C* LCD_type(LCD);
void LCD_putchar(LCD, byte, byte, char);
void LCD_write(LCD, byte, byte, char);
void LCD_clear(LCD type);
void LCD_createChar(LCD, byte, byte*);