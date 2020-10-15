/*

======================== ATELIER ROBOTIQUE : CatMini ========================
==                              Premiers pas                               ==
==                        Test capteur infrarouge                          ==
=============================================================================

Copyright (c) 2020 QI Informatique.



Test du montage avec le capteur infrarouge. 

Ce code permet de voir le code du bouton reçu par le capteur. 

*/




#include <IRremote.h> //on inclut la librairie nécéssaire pour les capteurs IR

#define RECV_IR 5 //déclaration du PIN du capteur 


IRrecv irrec(RECV_IR); //on dit au programme que ce Pin est un capteur IR
decode_results result ; //on crée une variable result pour recevoir les informations
//du capteur 

void setup() {

  Serial.begin(57600);
  irrec.enableIRIn(); //initialisation du capteur IR (il attend de recevoir un signal)
}

void loop() {
  
   if (irrec.decode(&result)){ //si une valeur est captée
      Serial.println(result.value, HEX); //On affiche la valeur du signal capté (HEX pour hexadecimal)  
      //comme cela on identifie le code de chacun des boutons 
      translateIR();
      irrec.resume(); //pour recevoir une nouvelle valeur 
       
   }
      

    
}

void translateIR() {//fonction pour associer une action à chaque bouton

  switch(result.value){ //switch permet de lister tous les cas possibles et 
    //de leur associer une action

    //on va donc lister tous les codes et retourner leur nom sur la télécommande

    case 0xFF18E7: Serial.println(" HAUT"); break;
    case 0xFF10EF: Serial.println(" GAUCHE");    break;
    case 0xFF38C7: Serial.println(" -OK-");    break;
    case 0xFF5AA5: Serial.println(" DROITE");   break;
    case 0xFF4AB5: Serial.println(" BAS"); break;
    case 0xFFA25D: Serial.println(" 1");    break;
    case 0xFF629D: Serial.println(" 2");    break;
    case 0xFFE21D: Serial.println(" 3");    break;
    case 0xFF22DD: Serial.println(" 4");    break;
    case 0xFF02FD: Serial.println(" 5");    break;
    case 0xFFC23D: Serial.println(" 6");    break;
    case 0xFFE01F: Serial.println(" 7");    break;
    case 0xFFA857: Serial.println(" 8");    break;
    case 0xFF906F: Serial.println(" 9");    break;
    case 0xFF6897: Serial.println(" *");    break;
    case 0xFF9867: Serial.println(" 0");    break;
    case 0xFFB04F: Serial.println(" #");    break;
    case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: //si le signal ne correspond à aucun de ces codes
    Serial.println("autre bouton ");

  }
  delay(500); //on doit attendre un peu pour éviter d'appuyer 2 fois
}
 
