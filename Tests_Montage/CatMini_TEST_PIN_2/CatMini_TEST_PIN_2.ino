/*

======================== ATELIER ROBOTIQUE : CatMini ========================
==                              Premiers pas                               ==
==                 Comment fonctionne une carte Arduino                    ==
=============================================================================

Copyright (c) 2020 QI Informatique.



Visualisation du fonctionnement d'Arduino avec un voltmètre

Ce code permet de voir comment la carte traduit la valeur HIGH et LOW. 

*/

const int PIN_TEST=2; //déclaration du pin 

void setup() {
  Serial.begin(57600); //initialisation du moniteur série 
  pinMode(PIN_TEST,OUTPUT); //pin comme sortie (la carte envoie un signal)
}

void loop() {
  Serial.println("HIGH !");
  digitalWrite(PIN_TEST, HIGH);
  delay(2000);
  Serial.println("LOW !");
  digitalWrite(PIN_TEST, LOW);
  delay(2000);
}
