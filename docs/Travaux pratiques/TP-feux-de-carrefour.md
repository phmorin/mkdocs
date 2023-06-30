# TP. Feux de carrefour

!!! abstract "Objectif"
    ![Feux](images/feu-tricolore.jpg){ align=right }
    On souhaite simuler le fonctionnement de feux d'un croisement de deux voies (A et B).
    On étudiera ici la mise en oeuvre d'une carte Arduino Uno et de modèles réduits de feux de carrefour.

    - réaliser la maquette à partir du schéma électronique, à l'aide d'une plaque d'expérimentation ;
    - saisir et comprendre le programme : créer d'autres fonctions que _setup_ et _loop_ ; utiliser l'instrution _millis()_ pour gérer les délais.
    - faire évoluer le programme pour y ajouter un deuxième feu, puis d'autres fonctions.

## Matériel nécessaire
- une carte Arduino Uno ;
- une plaque d'expérimentation ;
- deux feux tricolores ;
- 8 câbles male-male ;
- un câble USB A ;
- le logiciel Arduino.

## Schéma électronique

![Feux](images/schema-feu-A.png){width=600px}

## Représentation du fonctionnement des feux

On peut représenter le fonctionnement des feux de carrefour par ce _chronogramme_. On considère qu'il y a deux voies qui se croisent dans notre carrefour : la voie __A__ et la voie __B__ : 

![Chronogramme](images/chronogramme-feux-tricolores-sans-appel-pietons.png){width=800px}

## Programme et explications

### Informations générales
On décrit le programme dans un en-tête, au début du programme. Cette zone permet d'indiquer quelques informations principales : l'auteur du programme, l'organisme, éventuellement la version. __ Ne négligez pas cette partie !__  
Cette partie ne sera pas exécutée, elle appraît sous la forme d'un bloc de commentaires.

``` arduino
/*
/ Utilisation de la fonction millis() pour gérer 
/ les feux de carrefour.
/ Philippe Morin - Lycée Jules Verne 
*/
```

### Définition et déclaration des constantes

On définit quelques noms de constantes pour plus de lisibilité. Par exemple, à chaque fois que le programme rencontrera l'expression `feuRougeVoieA`, il la remplacera par la valeur `5`. Ces définitions seront créees avant compilation, ce ne sont donc pas des instructions. C'est pourquoi ces lilgne ne se terminent pas par un point-virgule.

``` arduino
#define feuRougeVoieA 5
#define feuOrangeVoieA 4
#define feuVertVoieA 3

unsigned long departCycle;

```

!!! note "Noms des variables et constantes"
    Remarquez la forme des noms de ces variables et constantes : chaque mot commence par une majuscule. On aurait pu aussi nommer `feu_rouge_voie_a`, par exemple. Choisissez un type de nom explicite, et tentez de le conserver.

### Intitialisation

La fonction `setup()` permet d'initialiser quelques éléments de notre programme :

- on indique que les broches utilisées seront gérées en _sortie_ (on envoie un courant) ;
- on initialise la variable qui indique le temps de départ de notre cycle en lui donnant la valeur `millis()` courante (quelques détails sur la fonction millis() sur [cette page](https://arduino-france.site/millis-arduino/){:target="_blank" }). 


``` arduino
void setup() {
  pinMode(feuRougeVoieA, OUTPUT);
  pinMode(feuOrangeVoieA, OUTPUT);
  pinMode(feuVertVoieA, OUTPUT);
 
  departCycle = millis();
}
```

### Fonction principale

La fonction principale d'un programme Arduino s'appelle `loop()`. Toute les instructions comprises dans cette fonction s'exécute les unes après les autres. À la fin de cette fonction, on recommence à exécuter les instructions, ceci indéfiniment.

``` arduino
void loop() {
 
  // Extinction des feux :
  digitalWrite(feuRougeVoieA, LOW);
  digitalWrite(feuOrangeVoieA, LOW);
  digitalWrite(feuVertVoieA, LOW);
 
  // Comparaison du temps passé avec le départ du cycle :
  if (millis() < (departCycle + 3000)) {passageVoieA();}  
  if ((millis() >= (departCycle + 3000)) && (millis() < (departCycle + 4000))) {transitionVoieA(); }
  if ((millis() >= (departCycle + 4000)) && (millis() < (departCycle + 8000))) {arretVoieA();;}
  if (millis() > (departCycle + 8000)) {departCycle = millis();}
}
```
#### Que se passe-t-il dans cette fonction ?

- On éteint tous les feux.
- On compare le temps actuel (`millis()`) avec le moment de départ du cycle :
    - s'il est inférieur à 3000, on laisse passer les voitures de la voie A (feu vert) ;
    - s'il est compris entre 3000 et 4000, on prépare la transition de la voie A vers l'arrêt des véhicules (feu orange) ;
    - s'il est compris entre 4000 et 8000, on arrête les voitures de la voie A (feu rouge) ;
    - Si ce temps est supérieur à 8000, on réinitialise le départ du cycle, puis on recommence.

on ne commande pas directement l'extinction et l'allumage des feux directement dans cette fonction, on passe par d'autres fonctions qui en ont la charge (`passageVoieA()`, `transitionVoieA()`, etc ). Ces fonctions sont définies dans la suite du programme :

### Fonctions d'extinction et d'allumage des feux

Elles se placent à la suite de la fonction `loop()`. Par exemple :

``` arduino
void passageVoieA() {
  digitalWrite(feuRougeVoieA, LOW);
  digitalWrite(feuOrangeVoieA, LOW);
  digitalWrite(feuVertVoieA, HIGH);
}
```

Les autres fonctions seront semblables.

## Programme complet
Il est téléchargeable ici : [feu-tricolore-1.ino](feu-tricolore-1/feu-tricolore-1.ino)

!!! bug "Travaux à réaliser"
    1. créer ce montage et tester le programme avec un seul feu.  
    2. câbler un deuxième feu tricolore, qui indiquera le fonctionnement pour les véhicules de la voie B. À vous de modifier le programme pour y insérer les extinctions et allumages du deuxième feu...

