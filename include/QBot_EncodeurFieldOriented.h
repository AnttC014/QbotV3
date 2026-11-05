#include <Encoder.h>//Lirairie externe pour utiliser des encodeurs

/////ENCODEURS

Encoder encodeurFOAvG(18,31);
Encoder encodeurFOAvD(19,38);
Encoder encodeurFOArG(3,49);
Encoder encodeurFOArD(2,A1);


//Fonction générique
float distanceLowLevelFO(Encoder encodeur){//Retourne une distance en cm
  
  return encodeur.read()/1440.0*8.0*PI;
  /*Diviser par 1440 c'est le nombre de "clic" par tour de roue
  Multiplier par pi*8 car les roues ont un diamètre de 8 cm*/
}

void resetEncoderFO(){
  encodeurFOAvG.write(0);
  encodeurFOAvD.write(0);
  encodeurFOArG.write(0);
  encodeurFOArD.write(0);
}


//Fonctions pour obtenir la valeur d'encodeur de chaque roue
float distanceAvGFO(){
  return -distanceLowLevelFO(encodeurFOAvG);//Négatif pour que la valeur augmente en avançant
}

float distanceAvDFO(){
  return distanceLowLevelFO(encodeurFOAvD);
}

float distanceArGFO(){
  return -distanceLowLevelFO(encodeurFOArG);//Négatif pour que la valeur augmente en avançant
}

float distanceArDFO(){
  return distanceLowLevelFO(encodeurFOArD);
}

//Fonction principale pour obtenir la distance parcourue globale
float distanceXFO(){
  return (distanceAvDFO() + distanceAvGFO() + distanceArGFO() + distanceArDFO())/4;
}

float distanceYFO(){
  return (-distanceAvDFO() + distanceAvGFO() - distanceArGFO() + distanceArDFO())/4;
}

float distanceXYFO(){
  return ( sqrt(distanceXFO()*distanceXFO() + distanceYFO()*distanceYFO()) );
}

//Fonctions pour obtenir la distance parcourue par un seul côté
float distanceDroiteFO(){
  return(distanceAvDFO() + distanceArDFO())/2;
}

float distanceGaucheFO(){
  return (distanceAvGFO() + distanceArGFO())/2;
}
