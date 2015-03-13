/**
* \file Camera.h
* \brief Definit la camera et ses fonctions
*/
#ifndef CAMERA_H
#define CAMERA_H

/**
* \struct Camera
* \brief Structure de la camera
*
* Contient les parametres intra/extra de la camera
*
*/
typedef struct
{
	int nRows;
	int nCols;
	float k1;
	float k2;
	float Cx;
	float Cy;
	float f;
	float dx;
	float dy;
	char * model;
	float K[9];
}Camera;

void Initialize_camera(Camera * c);

void undistort_fm(float uvu[], float uvd[], Camera * c);

#endif