# mechatronics-m5-atom-sample
Atomデバイスの使い方やサンプル
- Atom Matrix
- Atom Lite
- Atom Echo

## おすすめの使い方
上部メニューの「ファイル」から「環境設定」にある「スケッチブックの保存場所」のディレクトリにcloneすることで、それ以降「ファイル」-「スケッチブック」に本サンプルが表示されるようになります。
```
$ cd <スケッチブックの保存場所>
$ git clone git@github.com:wiccidu/mechatronics-m5-atom-sample.git
```
![image](https://user-images.githubusercontent.com/74119351/183296769-3933d25b-b98c-4778-a91c-7e5ec0bb6eaf.png)

## サンプル
- 1.basic: 基本的な機能のサンプル
- 2.middle: basicのサンプルを組み合わせた実践的なサンプル
- 3.advanced: 特定の回路/用途で利用できるサンプル

## Arduino IDE 初期設定
https://www.arduino.cc/en/software からArduino IDEをインストールした後のAtomシリーズを使うための初期設定手順

1. ボードマネージャのURL追加
上部メニューの「ファイル」から「環境設定」をクリックし、「追加のボードマネージャーのURL：」に以下を追加
```
https://dl.espressif.com/dl/package_esp32_index.json
```

2. ボード追加
上部メニューの「ツール」から「ボード」-「ボードマネージャ...」をクリックし、`esp32 by Espressif Systems`をインストール

<img src="https://user-images.githubusercontent.com/74119351/183291206-aee2fc80-8ea9-46dd-831c-fb68019591af.png" width="500px">

3. ライブラリ追加
上部メニューの「ツール」から「ライブラリを管理...」をクリックし、`M5Atom by M5Stack`と`FastLED by Daniel Garcia`をインストール

<img src="https://user-images.githubusercontent.com/74119351/183291247-3191c2d9-7a51-40a3-95ff-57a509f884a1.png" width="500px">

<img src="https://user-images.githubusercontent.com/74119351/183291272-f9950ed7-2047-4db5-b60f-a233c23163e6.png" width="500px">

## Arduino IDE ボードおよびアップロードボーレート設定
- ボード："ESP32 Pico Kit"
- upload speed："115200"

![image](https://user-images.githubusercontent.com/74119351/183291142-f84b3356-4e6a-4540-8440-052f2b396c9b.png)
