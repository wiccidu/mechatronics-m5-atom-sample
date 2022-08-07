# mechatronics-m5-atom-sample
Atomデバイスの使い方やサンプル
- Atom Matrix
- Atom Lite
- Atom Echo

## Arduino IDE 初期設定
1. ボードマネージャのURL追加
上部メニューの「ファイル」から「環境設定」をクリックし、「追加のボードマネージャーのURL：」に以下を追加
```
https://dl.espressif.com/dl/package_esp32_index.json
```

2. ボード追加
上部メニューの「ツール」から「ボード」-「ボードマネージャ...」をクリックし、`esp32 by Espressif Systems`をインストール

3. ライブラリ追加
上部メニューの「ツール」から「ライブラリを管理...」をクリックし、`M5Atom by M5Stack`と`FastLED by Daniel Garcia`をインストール

## Arduino IDE ボードおよびアップロードボーレート設定
- ボード："ESP32 Pico Kit"
- upload speed："115200"
![image](https://user-images.githubusercontent.com/74119351/183291142-f84b3356-4e6a-4540-8440-052f2b396c9b.png)

## サンプル
- adc
- led
- usb_serial
