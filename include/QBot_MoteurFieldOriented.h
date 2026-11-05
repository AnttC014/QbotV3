#include <Arduino.h>

/////MOTEURS


//Fonction de base pour controler la direction et la vitesse d'une roue.
void vitesseRoueLowLevelFO(int pinA, int pinB, int pinPWM, float vitesse){
  int _vitesse = vitesse;
  _vitesse = constrain(_vitesse,-100,100);// accepte des valeurs de -100 à 100

  _vitesse = map(_vitesse,-100,100,-255,255); //transfert ces valeurs sur la bonne plage PWM
  if(abs(_vitesse)<20){//dead band
    _vitesse=0;
  }
  bool direction = _vitesse >= 0; //avancer = True
  digitalWrite(pinA,!direction); //Pour avancer, la pin A est à 0 et la pin B est à 1
  digitalWrite(pinB,direction);
  analogWrite(pinPWM, abs(_vitesse));

  //Fix automatique pour régler la différence entre les deux modèles de shield
  if (pinPWM == 9){
    //Si on demande d'envoyer une information à la pin 9, on envoit la même à la pin 6
    //Donc les deux modèles de shields vont fonctionner
    analogWrite(6, abs(_vitesse));
  }
}


///////Définition des moteurs de chaque roues

void vitesseAvGFO(int vitesse){
  vitesseRoueLowLevelFO(34,35,12,vitesse);
}

void vitesseAvDFO(int vitesse){
  vitesseRoueLowLevelFO(36,37,8,vitesse);//inverse les pins A et B car le moteur de droite doit tourner à l'envers
}

void vitesseArGFO(int vitesse){
  /*Les shields avec un point rouge utilise la pin 6 au lieu de 9.
  La fonction distanceLowLevel gère automatiquement cette différence
  en envoyant l'information simultanément aux deux pins*/
  vitesseRoueLowLevelFO(43,42,9,vitesse);
}

void vitesseArDFO(int vitesse){
  vitesseRoueLowLevelFO(A5,A4,5,vitesse);//inverse les pins A et B car le moteur de droite tourne à l'envers
}

////////////Drive modes

void stopFO(){
  vitesseAvDFO(0);
  vitesseAvGFO(0);
  vitesseArDFO(0);
  vitesseArGFO(0);
} 

//Tous les drives prennents de valeurs de -100 à +100
void simpleDriveFO(int vitesse){//Avancer-reculer. + = en avant
  
  vitesseAvGFO(vitesse);
  vitesseAvDFO(vitesse);
  vitesseArGFO(vitesse);
  vitesseArDFO(vitesse);
}

void arcadeDriveFO(int vx, int vz){//Avancer et tourner. +x = avant, +z = tourne horaire
 
 int vg = vx+vz;
 int vd = vx-vz;


 vitesseAvGFO(vg);
 vitesseAvDFO(vd);
 vitesseArGFO(vg);
 vitesseArDFO(vd);
}

void mecanumDriveFO(int vx, int vy, int vz){//+x = en avant, +y = droite, +z = horaire

 int vAvG = vx+vz+vy;
 int vAvD = vx-vz-vy;
 int vArG = vx+vz-vy;
 int vArD = vx-vz+vy;

 vitesseAvGFO(vAvG);
 vitesseAvDFO(vAvD);
 vitesseArGFO(vArG);
 vitesseArDFO(vArD);
}

void mecanumDrviveFieldOrriented(int vx, int vy, int vz, double yaw){//+x = en avant, +y = droite, +z = horaire
  double yawRad;

  yawRad = radians(yaw); // besion de l'angle en radian pour les fonctions trigonométiques
  double newVx = vx * cos(yawRad) + vy * sin(yawRad); // matrice de rotation
  double newVy = -vx * sin(yawRad) + vy * cos(yawRad);
  
  int vAvG = newVx + newVy + vz;
  int vAvD = newVx - newVy - vz;
  int vArG = newVx - newVy + vz;
  int vArD = newVx + newVy - vz;

  vitesseAvGFO(vAvG);
  vitesseAvDFO(vAvD);
  vitesseArGFO(vArG);
  vitesseArDFO(vArD);
  
}

