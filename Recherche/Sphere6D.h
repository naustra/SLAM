/**
* \file Sphere6D.h
* \brief Definit une sphere random
*/
#ifndef SPHERE_H
#define SPHERE_H

/**
* \def NPOINTSRAND
* Definit le nombre de points random
*/
#define NPOINTSRAND 1000 

/**
* \struct Sphere
* \brief Structure de la sphere
*
* Contient les parametres de la sphere
*
*/
typedef struct
{
	float X[NPOINTSRAND];
	float Y[NPOINTSRAND];
	float Z[NPOINTSRAND];
	float theta[NPOINTSRAND];
	float phi[NPOINTSRAND];
	float lambda[NPOINTSRAND];
}Sphere6D;

void Initialize_sphere6D(Sphere6D * s);

#endif