/**
* \file Camera.c
* \brief Definit la camera et ses fonctions
*/
#include <stdlib.h>
#include <stdio.h>
#include "Camera.h"

/**
* \fn void Initialize_camera(Camera * c)
* \brief Initialise la camera
*
* \param[in, out] c la camera a initialiser
*/
void Initialize_camera(Camera * c)
{
	float d = 0.0112;

	c->nRows = 240;
	c->nCols = 320;
	c->k1 = 6.333e-2;
	c->k2 = 1.390e-2;
	c->Cx = 1.7945 / d;
	c->Cy = 1.4433 / d;
	c->f = 2.1735;
	c->dx = d;
	c->dy = d;
	c->model = "two distortion parameters";

	c->K[0] = c->f / d;
	c->K[1] = 0;
	c->K[2] = c->Cx;
	c->K[3] = 0;
	c->K[4] = c->f / d;
	c->K[5] = c->Cy;
	c->K[6] = 0;
	c->K[7] = 0;
	c->K[8] = 1;
}


