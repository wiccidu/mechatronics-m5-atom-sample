## atom lite ピンアサイン

### ピン配置 

公式より引用: http://docs.m5stack.com/en/core/atom_lite

<img src="https://user-images.githubusercontent.com/74119351/189160834-7683f33b-a457-4d2a-86dd-bbf54db16e4c.png" width="600px;">


### 関数別 機能一覧表

|PIN|G22|G19|G23|G33|G21|G25|G26|G32|
|-|-|-|-|-|-|-|-|-|
|TYPE|Pin|Pin|Pin|Pin|Pin|Pin|Grove|Grove|
|I2C|||||SCL|SDA|||
|SPI||MOSI|CLK|MISO|||||
|digitalRead()|○|○|○|○|○|○|○|○|
|analogRead()||||○||※|※|○|
|touchRead()||||○||||○|
|dacWrite()||||||○|○||
|digitalWrite()|○|○|○|○|○|○|○|○|
|ledcWrite()|○|○|○|○|○|○|○|○|

※GPIO25と26は、無線を利用していない場合は○ 、無線利用時にはX


### 内部回路図

<img src="(https://user-images.githubusercontent.com/74119351/189166451-5370a70b-2647-4a07-8162-e3e6d5111b34.png" width="600px;">
