int sensor1 = 16;
int sensor2 = 5;
int sensor3 = 4;
int sensor4 = 14;
int sensor5 = 12;
int buzzer = 13;

#include <TridentTD_LineNotify.h>

#define SSID        "xxxxxxxxxx"                                     //ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD    "xxxxxxxxxx"                                   //ใส่ รหัส Wifi
#define LINE_TOKEN  "xxxxxxxxxx" //ใส่ รหัส TOKEN ที่ได้มาจากข้างบน

void setup() {
  //Serial.begin(115200);
  //Serial.println();
  Serial.println(LINE.getVersion());

  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
  LINE.notify("เซ็นเซอร์ตรวจจับเปลวไฟ");

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  int val1 = digitalRead(sensor1);
  int val2 = digitalRead(sensor2);
  int val3 = digitalRead(sensor3);
  int val4 = digitalRead(sensor4);
  int val5 = digitalRead(sensor5);

  Serial.print("ค่าแสง 1 : ");
  Serial.print(val1);
  Serial.print("     ค่าแสง 2 : ");
  Serial.print(val2);
  Serial.print("     ค่าแสง 3 : ");
  Serial.print(val3);
  Serial.print("     ค่าแสง 4 : ");
  Serial.print(val4);
  Serial.print("     ค่าแสง 5 : ");
  Serial.println(val5);

  if(val1 == 1 | val2 == 1 | val3 == 1 | val4 == 1 | val5 ==1){
    digitalWrite(buzzer, LOW);
  }
  else{
    digitalWrite(buzzer, HIGH);
  }

  if (val1 == 1) {
    String LineText;
    String string1 = "ตรวจพบเปลวไฟตำแหน่งที่  1";
    LineText = string1;
    Serial.print("Line ");
    Serial.println(LineText);
    LINE.notify(LineText);
  }
  if (val2 == 1) {
    String LineText;
    String string2 = "ตรวจพบเปลวไฟตำแหน่งที่  2";
    LineText = string2;
    Serial.print("Line ");
    Serial.println(LineText);
    LINE.notify(LineText);
  }
  if (val3 == 1) {
    String LineText;
    String string3 = "ตรวจพบเปลวไฟตำแหน่งที่  3";
    LineText = string3;
    Serial.print("Line ");
    Serial.println(LineText);
    LINE.notify(LineText);
  }
  if (val4 == 1) {
    String LineText;
    String string4 = "ตรวจพบเปลวไฟตำแหน่งที่  4";
    LineText = string4;
    Serial.print("Line ");
    Serial.println(LineText);
    LINE.notify(LineText);
  }
  if (val5 == 1) {
    String LineText;
    String string5 = "ตรวจพบเปลวไฟตำแหน่งที่  5";
    LineText = string5;
    Serial.print("Line ");
    Serial.println(LineText);
    LINE.notify(LineText);
  }
}