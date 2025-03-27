/**
 * @file EmetteurRF.cpp
 * @brief Implémentation de la classe EmetteurRF
 */

#include "EmetteurRF.h"

/**
 * Constructeur par défaut
 */
EmetteurRF::EmetteurRF(HardwareSerial &portSerie, int pinReception,
                       int pinTransmission, int vitesse) : _portSerie(portSerie),
                                                           _pinReception(pinReception),
                                                           _pinTransmission(pinTransmission),
                                                           _vitesseTransmission(vitesse),
                                                           _idTrame(1)
{
}

/**
 * Constructeur de copie
 */
EmetteurRF::EmetteurRF(const EmetteurRF &autre) : _portSerie(autre._portSerie),
                                                  _pinReception(autre._pinReception),
                                                  _pinTransmission(autre._pinTransmission),
                                                  _vitesseTransmission(autre._vitesseTransmission),
                                                  _prefixe(autre._prefixe),
                                                  _separateur(autre._separateur),
                                                  _numeroSerre(autre._numeroSerre),
                                                  _idTrame(autre._idTrame),
                                                  _finTrame(autre._finTrame)
{
}

/**
 * Destructeur
 */
EmetteurRF::~EmetteurRF()
{
    // Pas de ressources à libérer
}

/**
 * Initialise l'émetteur RF
 */
void EmetteurRF::initialiser()
{
    _portSerie.begin(_vitesseTransmission, SERIAL_8N1,
                     _pinReception, _pinTransmission);
}

/**
 * Configure les paramètres de la trame
 */
void EmetteurRF::configurerTrame(String prefixe, char16_t separateur,
                                 uint8_t numeroSerre, String finTrame)
{
    _prefixe = prefixe;
    _separateur = separateur;
    _numeroSerre = numeroSerre;
    _finTrame = finTrame;
}

/**
 * Envoie une trame avec les données fournies
 */
String EmetteurRF::envoyerTrame(float temperature, char uniteTemp, uint8_t hygrometrie){
    String trame = _prefixe +
                   String(_numeroSerre) + String(_separateur) +
                   String(_idTrame) + String(_separateur) +
                   String(temperature) +
                   String(uniteTemp) + String(_separateur) +
                   String(hygrometrie) + _finTrame;

    _portSerie.print(trame);
    return trame;
}

/**
 * Incrémente l'identifiant de trame
 */
void EmetteurRF::incrementerIdTrame()
{
    _idTrame++;
}