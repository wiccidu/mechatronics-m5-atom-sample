#include <M5Atom.h>

#define RED     0
#define GREEN   1
#define BLUE    2
#define CYAN    3
#define MAGENTA 4
#define YELLOW  5
#define WHITE   6

void setup() {
    M5.begin(true, false, true);
    delay(50);
    M5.dis.drawpix(0, 0x00ff00);
}

int FSM = 0;

void loop() {
    if (M5.Btn.wasPressed()) {
        LED(FSM);
        FSM++;
        if (FSM >= 8) {
            FSM = 0;
        }
    }
    delay(50); 
    M5.update();
}

void LED(int c){
    switch (c) {
        case 0:
            M5.dis.drawpix(0, 0x007000);
            break;
        case 1:
            M5.dis.drawpix(0, 0x700000);
            break;
        case 2:
            M5.dis.drawpix(0, 0x000070);
            break;
        case 3:
            M5.dis.drawpix(0, 0x700070);
            break;
        case 4:
            M5.dis.drawpix(0, 0x007070);
            break;
        case 5:
            M5.dis.drawpix(0, 0x707000);
            break;
        case 6:
            M5.dis.drawpix(0, 0x707070);
            break;
        default:
            M5.dis.drawpix(0, 0x000000);
            break;
    }
}
