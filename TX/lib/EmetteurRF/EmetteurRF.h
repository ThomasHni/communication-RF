/**
 * @file EmetteurRF.h
 * @brief Classe pour gérer l'émission de données RF
 */

#ifndef EMETTEUR_RF_H
#define EMETTEUR_RF_H

#include <Arduino.h>

/**
 * @brief Classe pour la gestion d'un émetteur RF
 */
class EmetteurRF
{
  private:
    HardwareSerial& _portSerie;           // Port série utilisé
    const int       _pinReception;        // Pin de réception
    const int       _pinTransmission;     // Pin de transmission
    const int       _vitesseTransmission; // Vitesse de transmission

    String  _prefixe;     // Préfixe de la trame (ex: "SERRE")
    char    _separateur;  // Caractère de séparation
    uint8_t _numeroSerre; // Numéro de la serre
    uint8_t _idTrame;     // Identifiant de la trame
    String  _finTrame;    // Fin de la trame (ex: "\r\n")

  public:
    /**
     * @brief Constructeur par défaut
     * @param portSerie Port série à utiliser
     * @param pinReception Pin RX
     * @param pinTransmission Pin TX
     * @param vitesse Vitesse de transmission
     */
    EmetteurRF(HardwareSerial& portSerie, int pinReception, int pinTransmission, int vitesse);

    /**
     * @brief Constructeur de copie
     * @param autre Instance à copier
     */
    EmetteurRF(const EmetteurRF& autre);

    /**
     * @brief Destructeur
     */
    ~EmetteurRF();

    /**
     * @brief Initialise l'émetteur RF
     */
    void initialiser();

    /**
     * @brief Configure les paramètres de la trame
     * @param prefixe Préfixe de la trame
     * @param separateur Caractère de séparation
     * @param numeroSerre Numéro de la serre
     * @param finTrame Fin de trame
     */
    void configurerTrame(String prefixe, char16_t separateur, uint8_t numeroSerre, String finTrame);

    /**
     * @brief Envoie une trame avec les données fournies
     * @param temperature Température mesurée
     * @param uniteTemp Unité de température
     * @param hygrometrie Pourcentage d'humidité
     * @return Trame envoyée sous forme de chaîne
     */
    String envoyerTrame(float temperature, char uniteTemp, uint8_t hygrometrie);

    /**
     * @brief Incrémente l'identifiant de trame
     */
    void incrementerIdTrame();
};

#endif // EMETTEUR_RF_H