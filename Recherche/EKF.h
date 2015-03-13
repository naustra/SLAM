/**
* \file EKF.h
* \brief Definit l'EKF et ses fonctions utilisees couremment
*/

#ifndef EKF_H
#define EKF_H

/**
* \def TAILLE_VECT
* Definit la taille du tableau du vecteur d'etat
*/
#define TAILLE_VECT 100 // Taille du tableau du vecteur d'état

/**
* \def TAILLE_COV
* Definit la taille du tableau de la matrice de covariance (présentée en vecteur)
*/
#define TAILLE_COV 10000 // Taille du tableau de la matrice de covariance

/**
* \struct EKF_filter
* \brief Structure de l'EKF
*
* Contient le vecteur d'etat, de covariance et les variables du bruit
*
*/
typedef struct
{
	float x_k_k[TAILLE_VECT];
	float p_k_k[TAILLE_COV];
	int taille; // Taille vraiment utilisée par x_k_k et p_k_k
	float std_a;
	float std_alpha;
	float std_z;
	char * type;
}EKF_filter;

void ekf_filter(EKF_filter * f, float x_k_k[], float p_k_k[], int taille, float std_a, float std_alpha, float std_z, char * type);

void set_x_k_k(EKF_filter * f, float x_k_k[], int taille);

#endif
