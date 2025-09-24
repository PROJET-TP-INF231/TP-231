
#ifndef PRODUIT_VECTORIEL_H
#define PRODUIT_VECTORIEL_H

#define MAX_TAILLE 10

// Structure pour représenter un vecteur 3D
typedef struct {
    double x, y, z;
} Vecteur3D;

// Structure pour représenter un vecteur de taille variable
typedef struct {
    int taille;
    double elements[MAX_TAILLE];
} Vecteur;

// Structure pour représenter une matrice
typedef struct {
    int lignes;
    int colonnes;
    double matrice[MAX_TAILLE][MAX_TAILLE];
} Matrice;

// Prototypes pour les vecteurs 3D
void saisir_vecteur3d(Vecteur3D *v, const char *nom);
void afficher_vecteur3d(const Vecteur3D *v, const char *nom);
Vecteur3D produit_vectoriel_3d(const Vecteur3D *v1, const Vecteur3D *v2);
double produit_scalaire_3d(const Vecteur3D *v1, const Vecteur3D *v2);

// Prototypes pour les vecteurs généraux
void saisir_vecteur(Vecteur *v);
void afficher_vecteur(const Vecteur *v);
double produit_scalaire(const Vecteur *v1, const Vecteur *v2);

// Prototypes pour les matrices
void saisir_matrice(Matrice *m, int lignes, int colonnes);
void afficher_matrice(const Matrice *m);
Vecteur produit_vecteur_matrice(const Vecteur *v, const Matrice *m);
int compatible_vecteur_matrice(const Vecteur *v, const Matrice *m);

#endif