/*

======================== ATELIER ROBOTIQUE : CatMini ========================
==                           Des yeux pour MiniCat                         ==
==                      Découverte de la bibliothèque U8g2                 ==
=============================================================================

Copyright (c) 2020 QI Informatique.



Découverte de la bibliothèque U8g2 et de ses fonctionnalités

*/


// bibliothèques nécéssaires 
#include <U8g2lib.h>
#include <Wire.h>

// déclaration de l'objet "écran" de taille 128 x 64 pixels 
U8G2_SSD1306_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0);

// déclaration de l'image à afficher 
static const unsigned char cat_eye_bits[] PROGMEM= {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x03,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0xcf, 0xfe, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f,
   0x8f, 0x67, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7f, 0x8c, 0x04, 0xe8,
   0x03, 0x00, 0x00, 0x00, 0xc0, 0xef, 0x80, 0x04, 0xe4, 0x07, 0x00, 0x00,
   0x00, 0xf0, 0x2f, 0x80, 0x46, 0xc0, 0x0f, 0x00, 0x00, 0x00, 0xf8, 0x0b,
   0xa0, 0x02, 0x60, 0x3f, 0x00, 0x00, 0x00, 0xfc, 0x53, 0x80, 0x24, 0x20,
   0x3e, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x80, 0x20, 0x10, 0x7e, 0x00, 0x00,
   0x00, 0x4f, 0x03, 0x80, 0x30, 0x82, 0xf0, 0x00, 0x00, 0x00, 0xcf, 0x05,
   0x00, 0x00, 0x88, 0xf6, 0x01, 0x00, 0x80, 0x87, 0x04, 0x00, 0x00, 0x40,
   0xfa, 0x03, 0x00, 0xc0, 0x0f, 0x01, 0x00, 0x01, 0x00, 0xf8, 0x03, 0x00,
   0xc0, 0x01, 0x00, 0x80, 0x01, 0x00, 0x8d, 0x07, 0x00, 0xe0, 0x05, 0x00,
   0x80, 0x03, 0x00, 0x86, 0x0f, 0x00, 0xe0, 0x03, 0x00, 0x80, 0x03, 0x00,
   0x00, 0x0f, 0x00, 0xf0, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x0e, 0x00,
   0x70, 0x04, 0x00, 0xc0, 0x03, 0x00, 0x40, 0x0f, 0x00, 0xf8, 0x1d, 0x00,
   0xc0, 0x03, 0x00, 0x00, 0x0f, 0x00, 0x78, 0x3b, 0x02, 0xc0, 0x07, 0x00,
   0x00, 0x2a, 0x00, 0xb8, 0x60, 0x00, 0xc0, 0x07, 0x00, 0x40, 0x2c, 0x00,
   0x3c, 0x38, 0x00, 0xc0, 0x07, 0x00, 0x30, 0x3f, 0x00, 0x1c, 0x07, 0x00,
   0xc0, 0x07, 0x00, 0xdc, 0x3d, 0x00, 0xbc, 0x03, 0x00, 0xc0, 0x07, 0x00,
   0xf0, 0x3f, 0x00, 0x3c, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x7c, 0x7c, 0x00,
   0xfc, 0x0f, 0x00, 0xc0, 0x07, 0x00, 0xc0, 0x7b, 0x00, 0xfc, 0x07, 0x00,
   0xc0, 0x07, 0x00, 0xf0, 0x7b, 0x00, 0x5e, 0x00, 0x00, 0xc0, 0x07, 0x00,
   0xf0, 0x7b, 0x00, 0x9e, 0x04, 0x00, 0xc0, 0x07, 0x00, 0x80, 0x7f, 0x00,
   0xfe, 0x0f, 0x00, 0xc0, 0x07, 0x00, 0xf0, 0x77, 0x00, 0xfe, 0x3f, 0x00,
   0xc0, 0x07, 0x00, 0xc4, 0x7f, 0x00, 0xde, 0x0f, 0x00, 0xc0, 0x07, 0x00,
   0x06, 0x74, 0x00, 0xfc, 0x0f, 0x00, 0xc0, 0x07, 0x00, 0xc3, 0x7f, 0x00,
   0xfc, 0x3f, 0x00, 0xc0, 0x07, 0x00, 0xe0, 0x7f, 0x00, 0xbc, 0x1f, 0x00,
   0xc0, 0x07, 0x00, 0x20, 0x7f, 0x00, 0xfc, 0x07, 0x04, 0xc0, 0x07, 0x00,
   0x38, 0x3f, 0x00, 0xfc, 0x91, 0x02, 0xc0, 0x07, 0x00, 0xf0, 0x3e, 0x00,
   0xf8, 0xc0, 0x01, 0xc0, 0x07, 0x80, 0xf6, 0x3d, 0x00, 0xb8, 0xfb, 0x08,
   0xc0, 0x07, 0x40, 0xfd, 0x3f, 0x00, 0xf8, 0xff, 0x0c, 0xc0, 0x07, 0x00,
   0xf7, 0x1f, 0x00, 0xf8, 0xf1, 0x03, 0xc0, 0x07, 0x00, 0xc0, 0x1f, 0x00,
   0xf0, 0x9c, 0x07, 0xc0, 0x07, 0x00, 0x95, 0x0d, 0x00, 0xf0, 0xff, 0x19,
   0xc0, 0x87, 0xb0, 0xe7, 0x0f, 0x00, 0xe0, 0xff, 0x17, 0x80, 0x07, 0x20,
   0x7f, 0x0f, 0x00, 0xe0, 0xff, 0x2f, 0x80, 0x07, 0xe9, 0xfe, 0x07, 0x00,
   0xc0, 0xff, 0x3f, 0x80, 0x03, 0xfe, 0xf4, 0x03, 0x00, 0x80, 0xff, 0x1f,
   0x00, 0x01, 0xff, 0xf9, 0x03, 0x00, 0x80, 0xff, 0x6f, 0x00, 0x30, 0xff,
   0xfb, 0x01, 0x00, 0x00, 0x7f, 0x7f, 0x86, 0x90, 0xcf, 0xf6, 0x01, 0x00,
   0x00, 0xfe, 0xf7, 0x02, 0xa2, 0xcf, 0xef, 0x00, 0x00, 0x00, 0xfc, 0xf7,
   0x23, 0xa3, 0x6e, 0x7f, 0x00, 0x00, 0x00, 0xf8, 0xd3, 0xe7, 0xa4, 0x7f,
   0x3f, 0x00, 0x00, 0x00, 0xf0, 0xfd, 0x4f, 0xa4, 0xf7, 0x1f, 0x00, 0x00,
   0x00, 0xe0, 0xff, 0x9f, 0x28, 0xee, 0x0f, 0x00, 0x00, 0x00, 0xc0, 0xdf,
   0x96, 0x49, 0xde, 0x03, 0x00, 0x00, 0x00, 0x00, 0xff, 0x99, 0xe1, 0xfd,
   0x01, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xf7, 0x7e, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
   0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// initialisation 
void setup() {
  u8g2.begin();  // initialisation de l'écran 
}


void loop() {
     
  u8g2.firstPage();
  do {
  
  // écrire du texte 
  //u8g2.setFont(u8g2_font_ncenB08_tr); // choix de la police d'écriture 
//  u8g2.drawStr(0,10,"C'est super beau ! ");
//  u8g2.drawStr(0,20,"Profitez bien ");  // écrire un texte qui commence à la position X = 0 , Y = 10

//  u8g2.setFont(u8g2_font_unifont_t_symbols); // réglage de la police pour afficher des symboles 
//  u8g2.drawUTF8(50, 30, "♡ ♡ ♡ ♡ ♡ ♡");

  // dessiner des formes 
  //u8g2.drawFrame(10,30,30,30); // dessiner un rectangle : (10, 30) est la position de départ et (30,30)correspond à la hauteur et la largeur
  //u8g2.drawRFrame(10,30,30,30,3); // dessiner un rectangle avec bords arrondis : dernier argument -> rayon du coin  
  //u8g2.drawBox(50,30,30,30); // rectangle rempli 

  
  //u8g2.drawCircle( 100, 45, 15); // dessiner un cercle : centre X,Y puis rayon 
  //u8g2.drawDisc( 100, 45, 15); // disque : cercle plein 
  
  
  //u8g2.drawTriangle(50,30,50,50, 70,50); // triangle : coordonnées des 3 extrémités
  //u8g2.drawLine(0,0,128,64); // dessiner une ligne qui commence au point (0,0) et finit au point (128, 64)
  //u8g2.drawLine(0,64,128,0); // dessiner une ligne qui commence au point (0,64) et finit au point (128, 0)


  //u8g2.drawEllipse(64, 32, 15, 10, U8G2_DRAW_ALL); // dessiner une ellipse 
  //u8g2.drawEllipse(64, 32, 15, 10, U8G2_DRAW_UPPER_RIGHT); // dessiner la partie supérieure droite de l'ellipse 
  //u8g2.drawEllipse(64, 32, 15, 10, U8G2_DRAW_UPPER_LEFT); // dessiner la partie supérieure gauche de l'ellipse
  //u8g2.drawEllipse(64, 32, 15, 10, U8G2_DRAW_LOWER_LEFT); // dessiner la partie inférieure gauche de l'ellipse

  
  // afficher une image 
  u8g2.drawXBMP(30,0,65, 64, cat_eye_bits); // point de départ de l'image puis dimensions


    
  } while ( u8g2.nextPage() );
}
