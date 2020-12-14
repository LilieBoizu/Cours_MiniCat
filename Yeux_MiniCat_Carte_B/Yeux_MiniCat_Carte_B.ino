/*

======================== ATELIER ROBOTIQUE : CatMini ========================
==                           Des yeux pour MiniCat                         ==
==                     Ajout d'écrans LCD sur notre robot                  ==
=============================================================================

Copyright (c) 2020 QI Informatique.



Ajout de yeux pour MiniCat, avant de l'intégrer dans le code général.  

Ce code permet d'afficher différents yeux sur les écrans, pour donner des 
"émotions" au robot chat !  

*/






/* ENGLISH VERSION 
 *  
 * This code defines "mood" functions for MiniCat from drawings.  
 * Feel free to use your own images !
 *  
 *  
 * Details in README 
 * 
 */

#include <U8g2lib.h> // on inclut les bibliothèques nécéssaires
#include <Wire.h>


//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* reset=*/ U8X8_PIN_NONE);
// déclaration du type d'écran : largeur 128 pixels, hauteur 64 pixels
//U8G2_SSD1306_128X64_NONAME_2_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0);
/* 

===========================================================================
==                                                                       ==
==                DEFINITION DES IMAGES A AFFICHER                       ==
==               (possibilité de réduire l'affichage                     ==
==                                                                       ==
===========================================================================
 
*/

// XBM code for the images, see : https://sandhansblog.wordpress.com/2017/04/16/interfacing-displaying-a-custom-graphic-on-an-0-96-i2c-oled/
// to convert your own images 


static const unsigned char love_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x3f,
   0x00, 0x00, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x01, 0x00, 0xfc,
   0xff, 0x01, 0x00, 0x00, 0xff, 0xff, 0x03, 0x00, 0xff, 0xff, 0x07, 0x00,
   0xc0, 0xff, 0xff, 0x07, 0x80, 0xff, 0xff, 0x0f, 0x00, 0xe0, 0xff, 0xff,
   0x0f, 0xc0, 0xff, 0xff, 0x1f, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0xe0, 0xff,
   0xff, 0x3f, 0x00, 0xf0, 0xff, 0xff, 0x3f, 0xf0, 0xff, 0xff, 0x7f, 0x00,
   0xf8, 0xff, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0x7f, 0x00, 0xfc, 0xff, 0xff,
   0x7f, 0xf8, 0xff, 0xff, 0xff, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xf8, 0xff,
   0xff, 0xff, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0x01,
   0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x01, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01,
   0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x01, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01,
   0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfc, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x01, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
   0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x7f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00,
   0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x1f, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00,
   0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x80, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x07, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00,
   0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0xfe, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00,
   0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0xe0, 0xff,
   0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff,
   0x1f, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00,
   0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xff,
   0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff,
   0x01, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x3f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x03,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; 


static const unsigned char happy_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff,
   0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xfe, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff,
   0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff,
   0xcf, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
   0xff, 0xc7, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0xff, 0x87, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0xff, 0x01, 0xfe, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0xff, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x07,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0xf0, 0xff, 0xff, 0xff,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00, 0xe0, 0xff, 0xff,
   0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x1f, 0x00, 0xc0, 0xff,
   0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x0f, 0x00, 0x80,
   0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x07, 0x00,
   0x00, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x03,
   0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff,
   0x01, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xf8,
   0xff, 0x01, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00,
   0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x0f, 0x00,
   0x00, 0x00, 0xfe, 0x3f, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x1f,
   0x00, 0x00, 0x00, 0xff, 0x1f, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff,
   0x3f, 0x00, 0x00, 0x80, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff,
   0xff, 0x7f, 0x00, 0x00, 0xc0, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xfe,
   0xff, 0xff, 0xff, 0x00, 0x00, 0xe0, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0xf0, 0xff, 0x03, 0x00, 0x00, 0x00,
   0x00, 0xfc, 0xff, 0xff, 0xff, 0x03, 0x00, 0xf8, 0xff, 0x01, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x0f, 0x00, 0xf8, 0xff, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x1f, 0x00, 0xfc, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xfe, 0x3f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xff,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0x3f, 0x80,
   0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x0f,
   0xc0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff,
   0x07, 0xe0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff,
   0xff, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0xff, 0xff, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0xff, 0x3f, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xe0, 0xff, 0x0f, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xc0, 0xff, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00 };

static const unsigned char sleep_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00,
   0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x0c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00,
   0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x38, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x38, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00,
   0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x1e, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0xf0, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0x00,
   0x00, 0xe0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x80, 0x0f, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0xc0, 0x07, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x07, 0x00,
   0x00, 0xc0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x03, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x80, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00,
   0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x07,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x7f, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xf8, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff,
   0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfe, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe,
   0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x7f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x0f, 0x00,
   0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0xff, 0xff, 0x7f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff,
   0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff,
   0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static const unsigned char kill_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0x0e, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xc0, 0xff, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0x1f, 0x00, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x0f, 0x00,
   0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0xff, 0x0f,
   0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x01, 0x00, 0xfe, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0xe0, 0xff, 0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x7f, 0x00, 0x00, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1f,
   0x00, 0x00, 0xc0, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfe, 0x0f, 0x00, 0x00,
   0x80, 0xff, 0x07, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0xfe,
   0x1f, 0x00, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0x00, 0xfc, 0x7f, 0x00,
   0x00, 0xe0, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x01, 0x00, 0xf0,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x07, 0x00, 0xf8, 0x1f, 0x00,
   0x00, 0x00, 0x00, 0x80, 0xff, 0x1f, 0x00, 0xfe, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfe, 0x7f, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf8, 0xff, 0x80, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff,
   0xe3, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
   0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xef, 0xff, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xff, 0x87, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0xff, 0x01, 0xfe, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff,
   0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0xf0,
   0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x3f, 0x00, 0xc0, 0xff, 0x07,
   0x00, 0x00, 0x00, 0x00, 0xfe, 0x0f, 0x00, 0x00, 0xff, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0xc0,
   0xff, 0x01, 0x00, 0x00, 0xf0, 0xff, 0x01, 0x00, 0x00, 0xe0, 0xff, 0x00,
   0x00, 0x00, 0xe0, 0xff, 0x07, 0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00, 0x00,
   0x80, 0xff, 0x1f, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xfe,
   0x3f, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0x00,
   0x80, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x03, 0xe0, 0xff,
   0x01, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x07, 0xf0, 0x7f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xff, 0x0f, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0x0f, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x0f, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f,
   0xfe, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x3e, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00 };
/* 

===========================================================================
==                                                                       ==
==                FONCTIONS DEFINISSANT LES EMOTIONS DU ROBOT            ==
==                                                                       ==
===========================================================================
 
*/


// mood functions 

void mood(String mood){
  if (mood == "happy"){
    u8g2.drawXBMP(10, 3, 103, 58, happy_bits);
  }
  else if (mood == "sleep"){
    u8g2.drawXBMP(0, 13, 128, 51, sleep_bits);
  }
  else if (mood == "love"){
    u8g2.drawXBMP(30, 0 , 67, 64, love_bits);
  }
  else if (mood == "kill"){
    u8g2.drawXBMP(25, 0, 76, 64, kill_bits);
  }
  
}

void print_mood(String moodToPrint) {
   u8g2.firstPage();
  do {
    mood(moodToPrint);
  } while ( u8g2.nextPage() );
}


// Définition des actions à associer à chaque bouton de la télécommande IR 

// ---------------------------------------------------------------------------------


#include "IRremote.h"
int receiver = 5; 

IRrecv irrecv(receiver);     
decode_results results;      
String translateIR() 
{   
                                  
  switch (results.value) { // cette fois l'action est de renvoyer l'abréviation de la 
    // posture ou du mouvement demandé


    
                 //abbreviation of gaits      key on IR remote                gait/posture names
    case 0xFF18E7: return (F("vt"));        //Serial.println(" FORWARD");   //stepping on spot, "mark time"
    case 0xFF10EF: return (F("sit"));       //Serial.println(" LEFT");      //sit
    case 0xFF38C7: return (F("bd"));        //Serial.println(" -OK-");      //bound
    case 0xFF5AA5: return (F("balance"));   //Serial.println(" RIGHT");     //standing
    case 0xFF4AB5: return (F("d"));         //Serial.println(" REVERSE");   //shut down servos
    case 0xFFA25D: return (F("trL"));       //Serial.println(" 1");         //trot left
    case 0xFF629D: return (F("tr"));        //Serial.println(" 2");         //trot 
    case 0xFFE21D: return (F("trR"));       //Serial.println(" 3");         //trot right
    case 0xFF22DD: return (F("wkL"));       //Serial.println(" 4");         //walk left
    case 0xFF02FD: return (F("wk"));        //Serial.println(" 5");         //walk 
    case 0xFFC23D: return (F("wkR"));       //Serial.println(" 6");         //walk right
    case 0xFFE01F: return (F("crL"));       //Serial.println(" 7");         //crawl left
    case 0xFFA857: return (F("cr"));        //Serial.println(" 8");         //crawl
    case 0xFF906F: return (F("crR"));       //Serial.println(" 9");         //crawl right
    case 0xFF6897: return (F("bkL"));       //Serial.println(" *");         //back left
    case 0xFF9867: return (F("bk"));        //Serial.println(" 0");         //back
    case 0xFFB04F: return (F("bkR"));       //Serial.println(" #");         //back right
    case 0xFFFFFFFF: return (""); //Serial.println(" REPEAT");

    default:
      return ("");                      //Serial.println("null");
  }
}

String cmd ; 
String mood_cat ; 
bool new_cmd ; 

/* 

===========================================================================
==                                                                       ==
==                           SETUP & LOOP                                ==
==                                                                       ==
===========================================================================
 
*/



void setup() {

  // Initialisation moniteur série
  Serial.begin(57600);
  irrecv.enableIRIn(); //initialisation du capteur IR (il attend de recevoir un signal)
  // Initialisation des écrans 
  
  u8g2.begin(); // init for screens 
  print_mood("sleep");

  new_cmd = false ; 

}



void loop() {
  
  if (irrecv.decode(&results)) { // si on reçoit un signal IR 
      Serial.println(results.value, HEX);

      //cmd = translateIR();
      Serial.println(cmd);
    
      if (translateIR() != "") {
        cmd = translateIR(); // on copie dans "cmd" la commande reçue par le capteur IR 
        Serial.print("cmd :");
        Serial.println(cmd);
        new_cmd = true ; 
      }
      irrecv.resume(); // on se prépare pour recevoir un autre ordre 
    }


  // attribution des yeux à la bonne commande 

  if (new_cmd){ // si on a reçu une nouvelle commande 
     
    // si on appuie sur "rest" 
    if (cmd == "d"){
      print_mood("kill"); // afficher les yeux "kill"
      delay(500); // attendre 500 ms
      print_mood("sleep"); // afficher les yeux "sleep"
    }

    // si on appuie sur "sit"
    else if (cmd == "sit"){
      print_mood("love"); // afficher les yeux "love"
    }

    else {
      print_mood("happy"); // afficher les yeux "happy"
    }

    
    new_cmd = false ;
   }
  
}
