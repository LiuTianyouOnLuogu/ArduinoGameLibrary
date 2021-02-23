#include <ArduinoGameLibrary.h>

byte screen2004[4][20] = {}; // 0 -> 没有 1 -> 敌人 2 -> UFO
char screen1602[2][16] = {
    {'A', 'T', 'T', 'A', 'C', 'K', ':', 'O'},
    {}
};
byte enemy[8] = {
    0b00000,
    0b00100,
    0b01110,
    0b00100,
    0b01110,
    0b00100,
    0b01010,
    0b10001
}, UFO = {
    0b00000,
    0b00100,
    0b01110,
    0b11111,
    0b01110,
    0b00100,
    0b01010,
    0b10001
};
char this_key = 0;
byte UFO_place = 10, killed = -1;
int killed_begin = -1;

void update_2004(){
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 20; x++){
            if(screen2004[y][x] != 0){
                LCD_write(LCD2004, x+1, y+1, screen2004[y][x]);
            }
        }
    }
}

void update_1602(){
    for(int y = 0; y < 2; y++){
        for(int x = 0; x < 16; x++){
            LCD_putchar(LCD1602, x+1, y+1, screen1602[y][x]);
        }
    }
}

void setup(){
    LCD_createChar(LCD2004, 1, enemy);
    LCD_createChar(LCD2004, 2, UFO);
    while(true){
        if(killed_begin + 3000 >= mills()){
            killed_begin = -1;
            screen1602[0][8] = screen1602[0][9] =  'N';
            screen1602[0][9] = ' ';
        }
        for(int y = 0; y < 3; y++){
            for(int x = 0; x < 20; x++){
                if(killed == x) continue;
                screen2004[y][x] = random(0, 1); //有无敌人
            }
        }
        update_2004(); //刷新显存
        update_1602();
    }
}

void loop(){
    this_key = update_key(50);
    byte tmp = UFO_place;
    switch(this_key){ //为0（数字）表示没按键，4是左移，6是右移，5是攻击
        case '4':
            UFO_place --;
            break;
        case '6':
            UFO_place ++;
            break;
        case '5':
            killed = UFO_place;
            killed_begin = mills();
            screen1602[0][8] = screen1602[0][9] =  'F';
            break;
    }
    screen2004[3][tmp] = 0;
    screen2004[3][UFO_place] = 2;
}