#include <Arduino.h>

#include <FirebaseESP8266.h>
#define FIREBASE_HOST "YOUR_FIREBASE_PROJECT.firebaseio.com"
#define FIREBASE_AUTH "YOUR_FIREBASE_DATABASE_SECRET"
#define WIFI_SSID "YOUR_WIFI_AP"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

FirebaseData firebaseData;
String path = "/cmss/sensors"; //Se declara la rama de la base de datos a utilizar

void setup()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //Se inicializa la conexiòn con la red WiFi
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //Se inicializa la comunicaciòn con la base de datos
  Firebase.reconnectWiFi(true); //

  Firebase.enableClassicRequest(firebaseData, true); //Se permite el GET y POST de los datos en redes con Firewall

  pinMode(1, OUTPUT); //Se declara el pin 5 de Tx (GPIO-1) como salida
  digitalWrite(1, LOW); // Se sobreescribe el valor de GPIO-1 a 0
}

void loop()
{
  digitalWrite(1, LOW);
  delay(1000); // delay de 1 segundo
  digitalWrite(1, HIGH);
  delay(1000);
}