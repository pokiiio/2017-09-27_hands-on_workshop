#include <Nefry.h>

void setup() {

}

void loop() {
  Nefry.println("ON"); // シリアルモニタに出力
  Nefry.setLed(255, 0, 0); // LEDを光らせる
  Nefry.ndelay(1000); // 1秒待つ

  Nefry.println("OFF"); // シリアルモニタに出力
  Nefry.setLed(0, 0, 0); // LEDを消す
  Nefry.ndelay(1000); // 1秒待つ
}
