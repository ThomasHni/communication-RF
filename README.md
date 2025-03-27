![C++ Badge](https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=fff&style=plastic)
![PlatformIO Badge](https://img.shields.io/badge/build%20with-PlatformIO-orange?logo=platformio&logoColor=white&style=plastic)
![Windows Badge](https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white&style=plastic)

<!-- Badges de statut de compilation -->
![TX Build](https://img.shields.io/github/actions/workflow/status/ThomasHni/communication-RF/platformio.yml?branch=main&label=📡%20TX%20Build&logo=platformio&logoColor=white&style=plastic)
![RX Build](https://img.shields.io/github/actions/workflow/status/ThomasHni/communication-RF/platformio.yml?branch=main&label=📡%20RX%20Build&logo=platformio&logoColor=white&style=plastic)
![Code Style](https://img.shields.io/github/actions/workflow/status/ThomasHni/communication-RF/clang-format.yml?branch=main&label=🧹%20Code%20Style&logo=formatjs&logoColor=white&style=plastic)

# tp-module-communication RF

# tp-module-communication RF

**Objectifs :**



> [!NOTE]  
> Mettre en place une communication RF

- [Nomenclature](#nomenclature)
- [Programme principal](#programme-principal)

---

## Nomenclature

- une carte [Wemos D1 R32](https://www.az-delivery.de/fr/products/esp32-d1-r32-board)
  
<img src="./images/AzD1R32.jpg" height="200" width="200" alt="carte arduino R3">

---

Cette activité est à réaliser avec **PlatformIO** pour une carte ESP32 avec le _framework_ **Arduino**.

Le fichier de projet `platformio.ini` :

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
```

## Programme principal

Le fichier `src/main.cpp` initial :

```cpp

/**     // TO DO
 * @file main.cpp
 * @author your name
 * @brief 
 * @version 0.1
 * @date 2024-11-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
//////////////////////////////////////////////////////////////////////

#include <Arduino.h>

//////////////////////////////////////////////////////////////////////
void setup() {
   // TO DO
 }
//////////////////////////////////////////////////////////////////////
void loop() {
  // TO DO
}

```
=======
&copy;
