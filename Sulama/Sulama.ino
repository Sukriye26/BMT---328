#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char token[] = "9YEZI3TTCH5uhp8kdgHtBR_x7w_53mRV";
char agAdi[] = "TurkTelekom_T9B68";
char agSifre[]="7z0S0JgS";
#define sensor A0
int buzzerPin = 13;
int deger;
int donusum;

void setup(){
  pinMode(buzzerPin, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(token, agAdi, agSifre);
}

void loop() {
  deger = analogRead(sensor);
  donusum=map(deger ,0,1023,0,100);
  Blynk.virtualWrite (V1, donusum);
  Blynk.run();
  if(donusum<= 50){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(16,0);
    delay(100);
  }
  else{
    digitalWrite(buzzerPin, LOW);
    digitalWrite(16,1);
    delay(100);
  }
}
