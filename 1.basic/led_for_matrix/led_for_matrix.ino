#include <M5Atom.h>
void setup()
{
  M5.begin(true, false, true);
  delay(1000);
}

void loop(){
    M5.dis.drawpix(0, 0x000000);//消灯
    M5.dis.drawpix(1, 0x300000);
    M5.dis.drawpix(2, 0x700000);//緑の明るさ中間
    M5.dis.drawpix(3, 0xb00000);
    M5.dis.drawpix(4, 0xff0000);//緑の明るさ最大
    
    M5.dis.drawpix(5, 0x000000);//消灯
    M5.dis.drawpix(6, 0x003000);
    M5.dis.drawpix(7, 0x007000);//赤の明るさ中間
    M5.dis.drawpix(8, 0x00b000);
    M5.dis.drawpix(9, 0x00ff00);//赤の明るさ最大

    M5.dis.drawpix(10, 0x000000);//消灯
    M5.dis.drawpix(11, 0x000030);
    M5.dis.drawpix(12, 0x000070);//青の明るさ中間
    M5.dis.drawpix(13, 0x0000b0);
    M5.dis.drawpix(14, 0x0000ff);//青の明るさ最大

    M5.dis.drawpix(15, 0xffff00);//黄（緑＋赤）
    M5.dis.drawpix(16, 0xff00ff);//シアン,水色（緑＋青）
    M5.dis.drawpix(17, 0x00ffff);//マゼンタ,紫（赤＋青）
    M5.dis.drawpix(18, 0xffffff);//白（緑＋赤＋青）
    M5.dis.drawpix(19, 0x000000);//黒（消灯）

    M5.dis.drawpix(20, 0x000000);//消灯
    M5.dis.drawpix(21, 0x303030);
    M5.dis.drawpix(22, 0x707070);//白の明るさ中間
    M5.dis.drawpix(23, 0xb0b0b0);
    M5.dis.drawpix(24, 0xffffff);//白の明るさ最大
    delay(50);
    M5.update();
}