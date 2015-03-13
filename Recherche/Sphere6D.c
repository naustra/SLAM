/**
* \file Sphere6D.h
* \brief Definit une sphere random
*/
#include <stdlib.h>
#include <stdio.h>
#include "Sphere6D.h"
#include <time.h>
#include <math.h>

/**
* \fn void Initialize_sphere6D(Sphere6D * s)
* \brief Initialise la sphere 6D
*
* \param[in, out] s la sphere a initialiser
*/
void Initialize_sphere6D(Sphere6D * s)
{
	float temp;
	float a[6];

	for (int i = 0; i < NPOINTSRAND; i++)
	{
		temp = (rand() / (float)RAND_MAX) - (float)0.5;
		s->X[i] = temp;

		temp = (rand() / (float)RAND_MAX) - (float)0.5;
		s->Y[i] = temp;

		temp = (rand() / (float)RAND_MAX) - (float)0.5;
		s->Z[i] = temp;

		temp = (rand() / (float)RAND_MAX) - (float)0.5;
		s->theta[i] = temp;

		temp = (rand() / (float)RAND_MAX) - (float)0.5;
		s->phi[i] = temp;

		temp = (rand() / (float)RAND_MAX) - (float)0.5;
		s->lambda[i] = temp;
	}

	for (int i = 0; i < NPOINTSRAND; i++)
	{
		a[0] = s->X[i];
		a[1] = s->Y[i];
		a[2] = s->Z[i];
		a[3] = s->theta[i];
		a[4] = s->phi[i];
		a[5] = s->lambda[i];

		// Calcul de la norme 2 de a
		float sum=0;
		for (int j = 0; j < 6; j++)
		{
			sum += (a[j])*a[j];
		}
		float norm = (float)sqrt(sum);

		//Recalcul de a
		for (int j = 0; j < 6; j++)
		{
			a[j] = (a[j] / norm)*sqrt(12.59158724374398);
		}

		// On change les valeurs de la sphere
		s->X[i] = a[0];
		s->Y[i] = a[1];
		s->Z[i] = a[2];
		s->theta[i] = a[3];
		s->phi[i] = a[4];
		s->lambda[i] = a[5];
	}
}