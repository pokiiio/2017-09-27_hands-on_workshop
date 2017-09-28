#include <Nefry.h>
#include <WiFiClientSecure.h> // HTTP-GETのために必要

void setup() {

}

void loop() {
  String trainDelayJson = getTrainDelayJson();

  if (/** 遅延してたら **/) {
    Nefry.setLed(255, 0, 0); // 赤く光らせる
  } else {
    Nefry.setLed(0, 0, 255); // 青く光らせる
  }

  Nefry.ndelay(30000); // 30秒待つ
}

String getTrainDelayJson() {
  WiFiClientSecure client; // 変数を宣言

  // サーバーにHTTPSのデフォルトポート（443）でアクセスしてみる
  if ( !client.connect("rti-giken.jp", 443) ) {
    Nefry.println("接続失敗");
    return "";
  }

  client.print(String("GET /fhc/api/train_tetsudo/delay.json HTTP/1.1\r\n") +
               "Host: rti-giken.jp\r\n" +
               "Connection: close\r\n\r\n"); // HTTP-GETのリクエストメッセージを書く

  Nefry.ndelay(1000); // レスポンスが来るまでちょっと待つ

  String response = ""; // HTTP-GETのレスポンスを保存しておく変数

  while (client.available()) {
    response += client.readStringUntil('\r'); // レスポンスを変数に格納する
  }

  Nefry.println("接続成功");
  Nefry.println(response);

  return response;
}

