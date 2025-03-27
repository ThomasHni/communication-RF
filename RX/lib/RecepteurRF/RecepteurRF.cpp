/**
 * @file RecepteurRF.cpp
 * @brief Implémentation de la classe RecepteurRF
 */

#include "RecepteurRF.h"

/**
 * Constructeur par défaut
 */
RecepteurRF::RecepteurRF(HardwareSerial& portSerie,
                         int             pinReception,
                         int             pinTransmission,
                         int             vitesse) :
    _portSerie(portSerie), _pinReception(pinReception), _pinTransmission(pinTransmission),
    _vitesseTransmission(vitesse)
{
}

/**
 * Constructeur de copie
 */
RecepteurRF::RecepteurRF(const RecepteurRF& autre) :
    _portSerie(autre._portSerie), _pinReception(autre._pinReception),
    _pinTransmission(autre._pinTransmission), _vitesseTransmission(autre._vitesseTransmission)
{
}

/**
 * Destructeur
 */
RecepteurRF::~RecepteurRF()
{
    // Pas de ressources à libérer
}

/**
 * Initialise le récepteur RF
 */
void RecepteurRF::initialiser()
{
    _portSerie.begin(_vitesseTransmission, SERIAL_8N1, _pinReception, _pinTransmission);
}

/**
 * Vérifie si des données sont disponibles
 */
bool RecepteurRF::donneesDisponibles() const
{
    return _portSerie.available() > 0;
}

/**
 * Lit un message jusqu'au caractère de fin de ligne
 */
String RecepteurRF::lireMessage()
{
    return _portSerie.readStringUntil('\n');
}