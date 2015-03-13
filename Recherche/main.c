/**
* \file main.c
* \brief Programme principal
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "Camera.h"
#include "EKF.h"
#include "Sphere6D.h"

/**
* \fn int main()
* \brief Programme principal
*/
int main()
{
	/***************************/
	//Camera c1;

	//Initialize_camera(&c1);
	/****************************/
	//EKF_filter f;

	//float x_k_k[TAILLE_VECT] = { 0 };
	//float p_k_k[TAILLE_COV] = { 0 };

	//int taille;

	//initialize_x_and_p(x_k_k, p_k_k, &taille);

	//float sigma_a = 0.007;
	//float sigma_alpha = 0.007;
	//float sigma_image_noise = 1.0;

	//ekf_filter(&f, x_k_k, p_k_k, taille, sigma_a, sigma_alpha, sigma_image_noise, "constant_velocity");
	/*******************************/

	/** generate random 6D sphere **/
	Sphere6D s;
	srand(time(NULL));
	Initialize_sphere6D(&s);
	/******************************/ 

	return 0;
}