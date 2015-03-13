/**
* \file EKF.c
* \brief Definit l'EKF et ses fonctions utilisees couremment
*/

#include <stdlib.h>
#include <stdio.h>
#include "EKF.h"

/**
* \def EPS
* Definit l'epsilon
*/
#define EPS 2.2204e-16


/**
* \fn void initialize_x_and_p(float x_k_k[], int * x_ut, float p_k_k[], int * p_ut)
* \brief Initialise le vecteur d'etat et de covariance
*
* \param[in, out] x_k_k vecteur d'etat
* \param[in, out] p_k_k matrice de covariance
* \param[in] taille taille utilisee par les deux vecteurs
*/
void initialize_x_and_p(float x_k_k[], float p_k_k[], int * taille)
{
	// Définir les tailles utilisées par les 2 vecteurs
	*taille = 13;

	// Initial velocity values
	float v_0 = 0;
	float std_v_0 = 0.025;
	float w_0 = 1e-15;
	float std_w_0 = 0.025;

	// Initial state vector and covariance matrix
	// State vector :
	for (int i = 0; i < 13; i++)
	{
		switch (i)
		{
		case 3: x_k_k[i] = 1;
			break;
		case 7: x_k_k[i] = v_0;
			break;
		case 8: x_k_k[i] = v_0;
			break;
		case 9: x_k_k[i] = v_0;
			break;
		case 10: x_k_k[i] = w_0;
			break;
		case 11: x_k_k[i] = w_0;
			break;
		case 12: x_k_k[i] = w_0;
			break;
		default: x_k_k[i] = 0;
			break;
		}
	}

	// Covariance matrix
	for (int i = 0; i < 169; i++)
	{
		switch (i)
		{
		case 0: p_k_k[i] = EPS;
			break;
		case 14: p_k_k[i] = EPS;
			break;
		case 28: p_k_k[i] = EPS;
			break;
		case 42: p_k_k[i] = EPS;
			break;
		case 56: p_k_k[i] = EPS;
			break;
		case 70: p_k_k[i] = EPS;
			break;
		case 84: p_k_k[i] = EPS;
			break;
		case 98: p_k_k[i] = (float)(pow((double)std_v_0, 2));
			break;
		case 112: p_k_k[i] = (float)(pow((double)std_v_0, 2));
			break;
		case 126: p_k_k[i] = (float)(pow((double)std_v_0, 2));
			break;
		case 140: p_k_k[i] = (float)(pow((double)std_w_0, 2));
			break;
		case 154: p_k_k[i] = (float)(pow((double)std_w_0, 2));
			break;
		case 168: p_k_k[i] = (float)(pow((double)std_w_0, 2));
			break;
		default: p_k_k[i] = 0;
			break;
		}
	}
}

/**
* \fn void ekf_filter(EKF_filter * f, float x_k_k[], float p_k_k[], int taille, float std_a, float std_alpha, float std_z, char * type)
* \brief Initialise le filtre EKF
*
* \param[in, out] f le filtre a changer
* \param[in] x_k_k vecteur d'etat
* \param[in] p_k_k matrice de covariance
* \param[in] taille taille utilisee par les deux vecteurs
* \param[in] std_a
* \param[in] std_alpha
* \param[in] std_z
* \param[in] type du filtre
*/
void ekf_filter(EKF_filter * f, float x_k_k[], float p_k_k[], int taille, float std_a, float std_alpha, float std_z, char * type)
{
	f->type = type;
	for (int i = 0; i < taille; i++)
	{
		f->x_k_k[i] = x_k_k[i];
	}
	f->taille = taille;
	for (int i = 0; i < (taille^2); i++)
	{
		f->p_k_k[i] = p_k_k[i];
	}
	f->taille = taille;
	f->std_a = std_a;
	f->std_alpha = std_alpha;
	f->std_z = std_z;
}

// Gérer l'initialisation vide de l'EKF et celle de recopie ?

/**
* \fn void set_x_k_k(EKF_filter * f, float x_k_k[], int taille)
* \brief Change le vecteur d'etat
*
* \param[in, out] f le filtre a changer
* \param[in, out] x_k_k vecteur d'etat
* \param[in] taille taille utilisee par les deux vecteurs
*/
void set_x_k_k(EKF_filter * f, float x_k_k[], int taille)
{
	for (int i = 0; i < taille; i++)
	{
		f->x_k_k[i] = x_k_k[i];
	}
}