#include <M5Atom.h>

// 割込み内で使用する変数にはvolatile修飾子をつけ、保持領域を固定
volatile int count = 0;
volatile SemaphoreHandle_t timerSemaphore;  // 割り込み発生状態をloop()内で確認するためのバイナリセマフォ

// タイマ割込み設定
hw_timer_t * tim0 = NULL;                               // タイマー0の割り込みtim0で定義
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;   // 排他制御の利用を宣言

// tim0のタイマー割り込みハンドラ。この処理はsetupより先に書く
// タイマ割込み発生時に実行される処理 (IRAM_ATTRで宣言してRAM上に配置）
void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);  //排他制御開始（割込み禁止）
  // タイマ割り込み時の処理を記述
  count++;
  portEXIT_CRITICAL_ISR(&timerMux);   //排他制御終了（割り込み許可）
  xSemaphoreGiveFromISR(timerSemaphore, NULL);  //割込発生確認セマフォを開放
}

void setup() {
  M5.begin(false, false, true);

  // タイマ割込み設定
  timerSemaphore = xSemaphoreCreateBinary();  //割込発生確認セマフォを開放
  tim0 = timerBegin(0, 80, true);             //タイマー"0"を80MHz/"80"（1[us]）動作ｶｳﾝﾄｱｯﾌﾟでtim0に設定
  timerAttachInterrupt(tim0, &onTimer, true); //ハンドラ登録：tim0割込みが発生した時に実行する処理を指定「onTime」
  timerAlarmWrite(tim0, 1000000, true);       //割り込み周期登録：tim0割込み発生周期を1000ms（1[us] × 1000000）に設定
  timerAlarmEnable(tim0);                     //tim0タイマ割り込み開始（有効化）

  M5.dis.drawpix(0, 0x007000);
}

void loop() {
  M5.update();
  // 割込発生の確認セマフォが開放されているときのみ処理を実行
  if (xSemaphoreTake(timerSemaphore, 0) == pdTRUE) {
    if(count%2){
        M5.dis.drawpix(0, 0x707000);
    }else{
        M5.dis.drawpix(0, 0x700070);
    }
  }
}
