# Module-communication RF

<div align="center">

## A Propos
| Langage | Framework | OS |
|:-------:|:---------:|:--:|
| ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white) | ![PlatformIO](https://img.shields.io/badge/PlatformIO-orange?style=for-the-badge&logo=platformio&logoColor=white) | ![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white) |

## Status
| TX Build | RX Build | Clang-Format |
|:--------:|:--------:|:----------:|
| ![TX Build](https://img.shields.io/github/actions/workflow/status/ThomasHni/communication-RF/platformio.yml?branch=main&label=TX%20Build&logo=platformio&logoColor=white&style=for-the-badge) | ![RX Build](https://img.shields.io/github/actions/workflow/status/ThomasHni/communication-RF/platformio.yml?branch=main&label=RX%20Build&logo=platformio&logoColor=white&style=for-the-badge) | ![Code Style](https://img.shields.io/github/actions/workflow/status/ThomasHni/communication-RF/clang-format.yml?branch=main&label=Code%20Style&logo=prettier&logoColor=white&style=for-the-badge) |

[![Open in Visual Studio Code](https://img.shields.io/badge/Open_in-Visual_Studio_Code-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white)](vscode://file/c:/Users/thoma/Documents/Uni/communication-RF)

</div>

## Sommaire
- [Module-communication RF](#module-communication-rf)
  - [A Propos](#a-propos)
  - [Status](#status)
  - [Sommaire](#sommaire)
  - [Nomenclature](#nomenclature)
  - [Programme principal](#programme-principal)


**Objectifs :**

> [!NOTE]  
> Mettre en place une communication RF

## Nomenclature

  -  Carte [Wemos D1 R32](https://www.az-delivery.de/fr/products/esp32-d1-r32-board)
  
<img src="./img/AZD.png" height="200" width="200" alt="carte arduino R3">

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

---
&copy; 
Hnizdo Thomas 
