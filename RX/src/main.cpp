/**
 * @file main.cpp
 * @brief Programme principal du récepteur RF
 * @version 1.0
 * @date 2024-06-05
 */

#include <Arduino.h>
#include "RecepteurRF.h"

// Constantes
const int PIN_RECEPTION    = 16;
const int PIN_TRANSMISSION = 17;
const int VITESSE_CONSOLE  = 9600;
const int VITESSE_RF       = 200;
const int DELAI_AFFICHAGE  = 1000;

// Instances
HardwareSerial portRF(2);
RecepteurRF    recepteur(portRF, PIN_RECEPTION, PIN_TRANSMISSION, VITESSE_RF);

/**
 * @brief Initialisation du programme
 */
void setup()
{
    Serial.begin(VITESSE_CONSOLE);
    recepteur.initialiser();
    Serial.println("Récepteur RF initialisé");
}

/**
 * @brief Affiche le message reçu
 * @param message Message à afficher
 */
void afficherMessage(const String& message)
{
    Serial.println("Reçu: " + message);
}

/**
 * @brief Boucle principale
 */
void loop()
{
    if(recepteur.donneesDisponibles())
    {
        String message = recepteur.lireMessage();
        afficherMessage(message);
        delay(DELAI_AFFICHAGE);
    }
}