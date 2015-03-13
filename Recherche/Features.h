/**
* \file Features.h
* \brief Definit le tableau de points avec leurs informations
*/

#ifndef FEATURES_H
#define FEATURES_H

/**
* \def TAILLE_zhHS
* Definit la taille des tableaux de floats
*/
#define TAILLE_zhHS 5000 

/**
* \struct Features_info
* \brief Structure du vecteur de description des points
*
*/
typedef struct
{
	float patch_when_initialized[TAILLE_zhHS]; // Matrice carre
	int taille_init1; // Nb colonnes
	int taille_init1; // Nb lignes
	float patch_when_matching[TAILLE_zhHS]; // Matrice carre
	int taille_match;
	float r_wc_when_initialized[TAILLE_zhHS];
	int taille_r_wc;
	float R_wc_when_initialized[TAILLE_zhHS];
	int taille_R_wc;
	float uv_when_initialized[TAILLE_zhHS]; //uv ?
	int taille_uv;
	int half_patch_size_when_initialized;
	int half_patch_size_when_matching;
	int times_predicted;
	int times_measured;
	int init_frame;
	float init_measurement[TAILLE_zhHS]; //uv ?
	int taille_meas;
	char * type;
	float yi; // NewFeatures?
	int individually_compatible;
	int low_innovation_inlier;
	int high_innovation_inlier;
	float z[TAILLE_zhHS]; // Quelle taille choisir ?
	int taille_z;
	float h[TAILLE_zhHS];
	int taille_h;
	float H[TAILLE_zhHS];
	int taille_H;
	float S[TAILLE_zhHS];
	int taille_S;
	int state_size;
	int measurement_size;
	int R[4];
}Features_info;

void add_feature_to_info_vector(float uv[], float im_k[], float X_RES[], Features_info features_info, int step, newFeature);

#endif
