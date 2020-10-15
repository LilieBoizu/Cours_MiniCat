/*

======================== ATELIER ROBOTIQUE : CatMini ========================
==                              Premiers pas                               ==
==                        Test du servo driver                             ==
=============================================================================

Copyright (c) 2020 QI Informatique.



Test du montage avec le servo driver.  

Ce code permet de faire bouger un servomoteur.  

*/

//on inclut les librairies nécéssaires 


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> //librairie spécifique à notre servo driver 

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); //déclaration du driver pwm

#define SERVO 4 //pin où est branché le servomoteur 

#define SERVOMIN  150 // longueur "minimale" d'impulsion pour le servomoteur (sur 4096)
#define SERVOMAX  600 // longueur "maximale" d'impulsion pour le servomoteur (sur 4096)



int range = SERVOMAX - SERVOMIN; //intervale des longueurs d'impulsion accessibles 


void shutServo() { //fonction pour éteindre les servomoteurs 
  delay(250);
  pwm.setPWM(SERVO, 0, 4096); //ces paramѐtres permettent d'éteindre le servomoteur SERVO

}

void setup() {
  
  Serial.begin(57600);
  Serial.println("Servo test! Sur le Pin 4");

  pwm.begin(); //initialisation du servo driver

  pwm.setPWMFreq(60);  //fréquence du servomoteur 
  shutServo(); //éteindre le servomoteur avant de commencer 
  delay(1000);

}


void loop() {
  
  //Contrôle du servomoteur par longeur d'impulsion 
  Serial.println("position minimale");
  pwm.setPWM(SERVO, 0, SERVOMIN); //l'impulsion est large de SERVOMIN unités 
                                        //=>position minimale du servomoteur 
  delay(2000);
  
  Serial.println("position maximale");
  pwm.setPWM(SERVO, 0, SERVOMAX);//l'impulsion est large de SERVOMAX unités 
                                        //=>position maximale du servomoteur 
  delay(2000);
  
  Serial.println("position milieu");
  pwm.setPWM(SERVO, 0, SERVOMIN+range/2);//l'impulsion est large de SERVOMIN + range/2 unités 
                                        //=>position milieu du servomoteur 
  delay(2000);

  //Contrôle du servomoteur par angle (voir fonction setToAngle) 
  Serial.println("position 45 degrés ");
  setToAngle(45);
  
  Serial.println("position 20 degrés");
  setToAngle(20);
  

}



void setToAngle(int angle){ //permet de contôler le servomoteur directement par un angle 
                            //et plus par une longueur d'impulsion 
  
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX); //la fonction map transforme la valeur 
  //"angle", qui va de 0 à 180, en la valeur "pulse" qui va de SERVOMIN à SERVOMAX
  //On convertit notre angle en longueur d'impulsion !
  
  pwm.setPWM(SERVO, 0, pulse); //on envoie au servomoteur une impulsion longue de "pulse" unités
  delay(2000);
}
