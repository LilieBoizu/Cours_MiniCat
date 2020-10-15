/*

======================== ATELIER ROBOTIQUE : CatMini ========================
==                              Premiers pas                               ==
==                            Test de la carte                             ==
=============================================================================

Copyright (c) 2020 QI Informatique.



Test de la carte et rappel du fonctionnement d'Arduino 

Ce fichier fait clignoter la LED de la carte Arduino et affiche un message sur 
le moniteur série.  

*/



void setup() {
  

  pinMode(LED_BUILTIN, OUTPUT); // la LED BUILT-IN est une LED directement sur la 
  //carte 
  //on la défini comme "OUTPUT" (sortie)
  Serial.begin(57600); // initialisation du moniteur série 

  
}

void loop() {
  
  Serial.println("Test de la LED : Allume toi !"); //écriture sur le moniteur série 
  digitalWrite(LED_BUILTIN, HIGH); //on allume la LED (on lui envoie 5V)
  delay(2000); //on attend 2 secondes 
  Serial.println("Eteins-toi !");
  digitalWrite(LED_BUILTIN, LOW); //on éteint la LED (plus de tension envoyée)
  delay(2000);
}
