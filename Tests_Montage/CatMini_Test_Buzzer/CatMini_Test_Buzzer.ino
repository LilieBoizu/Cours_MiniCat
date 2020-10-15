/*

======================== ATELIER ROBOTIQUE : CatMini ========================
==                              Premiers pas                               ==
==                            Test du Buzzer                               ==
=============================================================================

Copyright (c) 2020 QI Informatique.
Code inspiré de Rongzhong Li


Test du buzzer et rappel du fonctionnement d'Arduino 

Ce code fait biper le buzzer actif de la carte Arduino et joue une mélodie.

*/

#define BUZZER 4 //définition du pin du buzzer


void beep(int note, float duration = 10, int pause = 0, byte repeat = 1) { //création d'une fonction pour faire biper 
  //le buzzer a une certaine note (par défaut duration = 10) 
  if (note == 0) { 
    analogWrite(BUZZER, 0); //on éteint le buzzer
    delay(duration); //on attend le temps de duration (en millisecondes)
    return; //on sort de la fonction 
  }

  int freq = 220 * pow(1.059463, note); //formule connue 
  float period = 1000000.0 / freq / 2.0; //formule connue
  for (byte r = 0; r < repeat; r++) {
    for (float t = 0; t < duration * 1000; t += period * 2) {
      analogWrite(BUZZER, 150);      //on allume le buzzer
      delayMicroseconds(period);          //on attend le temps de period (en microsecondes)
      analogWrite(BUZZER, 0);       //on éteint le buzzer
      delayMicroseconds(period);         //on attend le temps de period (en microsecondes)
    }
    delay(pause);
  }
}

void playMelody(byte m[], int len) { // fonction qui permet de jouer une suite de notes 
  for (int i = 0; i < len; i++)
    beep(m[i], 1000 / m[len + i], 100); // pour toutes les notes de la liste de note, on joue la note
}
void setup() {
  

  Serial.begin(57600); //initialisation du miniteur série
  pinMode(BUZZER, OUTPUT); //buzzer défini comme une sortie : on lui envoie des ordres

}


void loop() {
  
  
  byte melody[] = {8, 13, 10, 13, 8, 0, 5, 8, 3, 5, 8,   // définition de la suite de notes
                   8, 8, 32, 32, 8, 32, 32, 32, 32, 32, 8
                   //8,8,16,16,8,16,16,16,16,8
                  };
  playMelody(melody, sizeof(melody) / 2); // on joue la mélodie 
}
