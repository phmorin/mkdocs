# TP. Mesure de la température avec un capteur DHT22

!!! note "Objectifs"
    On souhaite dans ce TP mesurer la température avec un capteur DHT22.  
    Ce capteur se branche sur une broche numérique d'une carte électronique type Arduino ou Esp32...  
    __Comment sont envoyées les informations d'humidité et de température du capteur vers la carte ?__

## Matériel nécessaire
- [DHT 22](https://www.gotronic.fr/art-module-capteur-t-et-humidite-sen-dht22-31502.htm){target=_blank}.
- Carte électronique type [Arduino Uno](https://www.gotronic.fr/art-arduino-uno-a000066-12420.htm){target=_blank} ou [ESP32](https://www.gotronic.fr/art-module-nodemcu-esp32-28407.htm){target=_blank}.
- [Analyseur logique](https://amzn.eu/d/0e806SJ){target=_blank} et [son logiciel](https://www.saleae.com/downloads/){target=_blank}, à télécharger et à installer.

## Câblage


## Programme

Le programme en entier :

!!! warning "Attention !"
    Le seul point à surveiller est le numéro de la broche utilisée. Dans ce cas, `brocheDHT` est la broche 23 (la carte utilisée est une ESP32).

``` arduino

#include "DHT.h"
 
// Définit la broche de l'Arduino sur laquelle la 
// broche DATA du capteur est reliée 
#define brocheDHT 23
 
// Definit le type de capteur utilisé
#define DHTTYPE DHT22
 
// Declare un objet de type DHT
// Il faut passer en parametre du constructeur 
// de l'objet la broche et le type de capteur
DHT dht(brocheDHT, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
   
  // Initialise le capteur DHT22
  dht.begin();
}
 
void loop() {
  // Récupère la température et l'humidité du capteur et l'affiche
  // sur le moniteur série
  Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
  Serial.println("Humidite = " + String(dht.readHumidity())+" %");
 
  // Attend 10 secondes avant de reboucler
  delay(10000);
}
```
