/**
 * @file main.cpp
 * @brief Programme principal de l'émetteur RF
 * @version 1.0
 * @date 2024-06-05
 */

#include <Arduino.h>
#include "EmetteurRF.h"

// Constantes
const int PIN_RECEPTION    = 16;
const int PIN_TRANSMISSION = 17;
const int VITESSE_CONSOLE  = 9600;
const int VITESSE_RF       = 200;
const int DELAI_ENVOI      = 1000;

// Paramètres de la trame
const String  PREFIXE_TRAME = "SERRE";
const char    SEPARATEUR    = ';';
const uint8_t NUMERO_SERRE  = 1;
const String  FIN_TRAME     = "\r\n";

// Données du capteur (simulées)
float          temperature       = 25.5;
const char16_t UNITE_TEMPERATURE = 'C';
uint8_t        hygrometrie       = 60;

// Instances
HardwareSerial portRF(2);
EmetteurRF     emetteur(portRF, PIN_RECEPTION, PIN_TRANSMISSION, VITESSE_RF);

/**
 * @brief Initialisation du programme
 */
void setup()
{
    Serial.begin(VITESSE_CONSOLE);
    emetteur.initialiser();
    emetteur.configurerTrame(PREFIXE_TRAME, SEPARATEUR, NUMERO_SERRE, FIN_TRAME);
    Serial.println("Émetteur RF initialisé");
}

/**
 * @brief Affiche un message dans la console
 * @param message Message à afficher
 */
void afficherMessage(const String& message)
{
    Serial.println("Envoyé: " + message);
}

/**
 * @brief Boucle principale
 */
void loop()
{
    String trameSortante = emetteur.envoyerTrame(temperature, UNITE_TEMPERATURE, hygrometrie);
    afficherMessage(trameSortante);

    emetteur.incrementerIdTrame();
    delay(DELAI_ENVOI);
}