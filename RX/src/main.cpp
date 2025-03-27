#include <Arduino.h>
#define RX 16
#define TX 17
HardwareSerial uC1(2);

void setup()
{
    Serial.begin(9600);                 // init vitesse transmition
    uC1.begin(200, SERIAL_8N1, RX, TX); // init reception
}

void loop()
{
    if (uC1.available())
    {
        String message = uC1.readStringUntil('\n'); // reception
        Serial.println("Recu:" + message);          // affichage
        delay(1000);
    }
}
