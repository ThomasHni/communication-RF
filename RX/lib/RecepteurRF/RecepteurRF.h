/**
 * @file RecepteurRF.h
 * @brief Classe pour gérer la réception de données RF
 */

#ifndef RECEPTEUR_RF_H
#define RECEPTEUR_RF_H

#include <Arduino.h>

/**
 * @brief Classe pour la gestion d'un récepteur RF
 */
class RecepteurRF
{
private:
    HardwareSerial &_portSerie;     // Port série utilisé
    const int _pinReception;        // Pin de réception
    const int _pinTransmission;     // Pin de transmission
    const int _vitesseTransmission; // Vitesse de transmission

public:
    /**
     * @brief Constructeur par défaut
     * @param portSerie Port série à utiliser
     * @param pinReception Pin RX
     * @param pinTransmission Pin TX
     * @param vitesse Vitesse de transmission
     */
    RecepteurRF(HardwareSerial &portSerie, int pinReception, int pinTransmission, int vitesse);

    /**
     * @brief Constructeur de copie
     * @param autre Instance à copier
     */
    RecepteurRF(const RecepteurRF &autre);

    /**
     * @brief Destructeur
     */
    ~RecepteurRF();

    /**
     * @brief Initialise le récepteur RF
     */
    void initialiser();

    /**
     * @brief Vérifie si des données sont disponibles
     * @return vrai si des données sont disponibles
     */
    bool donneesDisponibles() const;

    /**
     * @brief Lit un message jusqu'au caractère de fin de ligne
     * @return Message reçu
     */
    String lireMessage();
};

#endif // RECEPTEUR_RF_H