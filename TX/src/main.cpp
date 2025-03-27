#include <Arduino.h>
#define RX 16
#define TX 17
HardwareSerial uC2(2);

char16_t separa = ';';
String SERRE = "SERRE";
uint8_t nserre = 1;// numéro de serre
uint8_t id = 1; //numero de trame
float_t valTemp = 25.5;//température
char16_t uniTemp = 'C';//unité de température
uint8_t valHygro = 60;//pourcentage d'hmidité
String fin = "\r\n";

void setup() {
Serial.begin(9600);//init vitesse transmition
uC2.begin(200,SERIAL_8N1,RX,TX);//init transmition
}

void loop() {
uC2.println(SERRE + String(separa) + String(nserre) + String(separa) + String(id) + String(separa) + String(valTemp) + String(separa) + String(uniTemp) + String(separa) + String(valHygro) + fin);// envoi de la trame

Serial.println("envoyé:"+ SERRE + String(separa) + String(nserre) + String(separa) + String(id) + String(separa) + String(valTemp) + String(separa) + String(uniTemp) + String(separa) + String(valHygro) + fin);// affichage de la trame
delay(1000);
id++;
}
