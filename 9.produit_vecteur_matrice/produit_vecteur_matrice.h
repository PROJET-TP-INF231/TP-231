#ifndef PRODUIT_VECTEUR_MATRICE_H
#define PRODUIT_VECTEUR_MATRICE_H

#define MAX_TAILLE 10

// Structure pour représenter un vecteur
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

// Prototypes des fonctions
void saisir_vecteur(Vecteur *v);
void afficher_vecteur(const Vecteur *v, const char *nom);
void saisir_matrice(Matrice *m, int lignes, int colonnes);
void afficher_matrice(const Matrice *m);
Vecteur produit_vecteur_matrice(const Vecteur *v, const Matrice *m);
int compatible_vecteur_matrice(const Vecteur *v, const Matrice *m);
void exemples_automatiques(void);

#endif