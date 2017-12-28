#include <SoftwareSerial.h>

SoftwareSerial BLU(0,1);

String voice;
int in2 = 7;
int led1 = 6;
int led2 = 5;

void allon() {
  digitalWrite(in2, HIGH);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
}

void alloff() {
  digitalWrite(in2, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void setup() {
  Serial.begin(9600);
  BLU.begin(9600);
  pinMode(in2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
 while (Serial.available()) 
 {
    delay (10);
    char c = Serial.read();

    if (c == '#')
    {
      break;
    }

    voice += c;
 }
 
 if (voice.length() > 0)
 {
    if (voice == "*semua hidup" || voice == "*1")
    {
      allon();
    }
    else if (voice == "*semua mati" || voice == "*2")
    {
      alloff();
    }
    if (voice == "*Jarwo Nyalakan TV")
    {
      digitalWrite(led1, HIGH);
    }
    else if (voice == "*Jarwo Matikan TV")
    {
      digitalWrite(led1, LOW);
    }
    if (voice == "*Jarwo nyalakan kipas")
    {
      digitalWrite(led2, HIGH);
    }
    else if (voice == "*Jarwo matikan kipas")
    {
      digitalWrite(led2, LOW);
    }
    if (voice == "*Jarwo nyalakan lampu")
    {
      digitalWrite(in2, HIGH);
    }
    else if (voice == "*Jarwo Matikan lampu")
    {
      digitalWrite(in2, LOW);
    }
    voice = "";
 }
}
