/*Cette librairie contient des fonctions permettant une utilisation facile
du robot mecanum de MoebiusTech :
 https://github.com/MoebiusTech/MecanumRobot-ArduinoMega2560

Nous utilisons ce robot comme la 3e génération du projet "Qbot" du cours de
robotique de 3e secondaire de la Polyvalente de Charlesbourg. 

Cette librairie a été conçue par Vincent Lavoie, Jayson Poirier et Samuel Tremblay.
 
Contact : samuel.tremblay.2@cssps.gouv.qc.ca

Creative Commons BY-NC-SA

V3.0 : Release initial, décembre 2020.
V3.1 : Ajout de la procédure pour corriger le pinout différent 
       des shields achetés l'été précédent, décembre 2022.
V3.2 : Gestion automatique des 2 modèles de shields, renommer
       les fonctions Toggle en UneFois pour mieux refléter leur
       fonction. Avril 2023
V3.3 : Dédoublement des fonctions "boutons" de la manette pour
       accomoder les deux modèles différents de manettes.
       Novembre 2024.
*/

//Tous ces fichiers doivent être dans le dossier "include"
#include <QBot_Capteur.h>
#include <QBot_Encodeur.h>
#include <QBot_EncodeurFieldOriented.h>
#include <QBot_Gyro.h>
#include <QBot_Moteur.h>
#include <QBot_MoteurFieldOriented.h>
#include <QBot_Servo.h>


