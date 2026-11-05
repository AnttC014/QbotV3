#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <Qbot.h> //Ce fichier doit être dans le dossier "include"

Manette manette;
float yaw;

void setup() {
  Serial.begin(9600);
  manette.begin();
  gyroBegin(0,0,0);
  //servoBegin();
  
}

void loop() {
  double factor = 0.75;
  yaw = angle();

  mecanumDrviveFieldOrriented( int(manette.LY() * factor) , int(manette.LX() * factor) , int(manette.RX() * factor) , yaw);
}