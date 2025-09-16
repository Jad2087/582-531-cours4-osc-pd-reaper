#include <Arduino.h>

#include <FastLED.h>
CRGB monPixel;

#define MA_BROCHE_BOUTON 39

# define MA_BROCHE_ANGLE 32

#include <MicroOscSlip.h>
// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.
// Les messages sortants sont écrits directement sur la sortie et ne nécessitent pas de réservation d'octets supplémentaires.
MicroOscSlip<128> monOsc(&Serial);

//enfin

void setup() {

  Serial.begin(115200);

  pinMode( MA_BROCHE_BOUTON , INPUT );
  
  FastLED.addLeds<WS2812,27,GRB> ( & monPixel, 1 );
  
}

void loop() {
  int maLectureBouton;
  maLectureBouton = digitalRead( MA_BROCHE_BOUTON );

  monOsc.sendInt( "/bouton" , maLectureBouton ); 

  delay(200);

  int maLectureAngle;
  maLectureAngle = analogRead(MA_BROCHE_ANGLE); 
  
  monOsc.sendInt("/angle" , maLectureAngle);

  monPixel = CRGB(0, millis()% 255, 0);

  FastLED.show();
}