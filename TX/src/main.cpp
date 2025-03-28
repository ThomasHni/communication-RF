/**
 * @file main.cpp
 * @brief Programme principal de l'émetteur RF avec capteur DHT22
 * @author HNIZDO Thomas
 * @version 1.1
 * @date 2025-03-28
 */

#include <Arduino.h>
#include "EmetteurRF.h"
#include <DHT.h>
#include <Adafruit_Sensor.h>

// Constantes pour le DHT22
#define BROCHE_DHT 12 // Broche DHT22
#define TYPE_DHT   DHT22

// Constantes pour l'émetteur RF
const int BROCHE_RECEPTION    = 16;
const int BROCHE_TRANSMISSION = 17;
const int VITESSE_CONSOLE     = 9600;
const int VITESSE_RF          = 200;
const int DELAI_ENVOI         = 1000;

// Paramètres de la trame
const String  PREFIXE_TRAME = "SERRE";
const char    SEPARATEUR    = ';';
const uint8_t NUMERO_SERRE  = 1;
const String  FIN_TRAME     = "\r\n";

// Constantes pour les données
const char16_t UNITE_TEMPERATURE = 'C';

// Instances
HardwareSerial portSerie(2);
EmetteurRF     emetteurRF(portSerie, BROCHE_RECEPTION, BROCHE_TRANSMISSION, VITESSE_RF);
DHT            capteurDht(BROCHE_DHT, TYPE_DHT);

/**
 * @brief Initialisation du programme
 */
void setup()
{
    Serial.begin(VITESSE_CONSOLE);
    capteurDht.begin();
    emetteurRF.initialiser();
    emetteurRF.configurerTrame(PREFIXE_TRAME, SEPARATEUR, NUMERO_SERRE, FIN_TRAME);
    Serial.println("Émetteur RF initialisé avec capteur DHT22");
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
 * @brief Lit les données du capteur DHT22
 * @param temperature Variable pour stocker la température
 * @param humidite Variable pour stocker l'humidité
 * @return true si la lecture est réussie, false sinon
 */
bool lireDHT22(float& temperature, uint8_t& humidite)
{
    // Lecture de l'humidité
    float valeurHumidite = capteurDht.readHumidity();
    // Lecture de la température en Celsius
    float valeurTemperature = capteurDht.readTemperature();

    // Vérifie si la lecture a échoué
    if(isnan(valeurHumidite) || isnan(valeurTemperature))
    {
        Serial.println("Échec de lecture du capteur DHT22!");
        return false;
    }

    temperature = valeurTemperature;
    humidite    = static_cast<uint8_t>(valeurHumidite);
    return true;
}

/**
 * @brief Boucle principale
 */
void loop()
{
    float   temperature;
    uint8_t tauxHumidite;

    if(lireDHT22(temperature, tauxHumidite))
    {
        String trameEnvoi = emetteurRF.envoyerTrame(temperature, UNITE_TEMPERATURE, tauxHumidite);
        afficherMessage(trameEnvoi);

        // Affiche également les valeurs sur le moniteur série
        Serial.print("Température: ");
        Serial.print(temperature);
        Serial.print(" °C, Humidité: ");
        Serial.print(tauxHumidite);
        Serial.println(" %");

        emetteurRF.incrementerIdTrame();
    }

    delay(DELAI_ENVOI);
}