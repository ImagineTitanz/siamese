#include <Arduino.h>
#include <FirebaseESP8266.h>

void setup()
{
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
}

void loop()
{
  digitalWrite(1, LOW);
  delay(1000); // delay de 1 segundo
  digitalWrite(1, HIGH);
  delay(1000);
}