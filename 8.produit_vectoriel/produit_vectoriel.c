
#include <stdio.h>
#include <math.h>
#include "produit_vectoriel.h"

// === FONCTIONS POUR VECTEURS 3D ===//

// Fonction pour saisir un vecteur 3D
void saisir_vecteur3d(Vecteur3D *v, const char *nom) {
    printf("Saisie du vecteur %s :\n", nom);
    printf("Composante x : ");
    scanf("%lf", &v->x);
    printf("Composante y : ");
    scanf("%lf", &v->y);
    printf("Composante z : ");
    scanf("%lf", &v->z);
}

// Fonction pour afficher un vecteur 3D
void afficher_vecteur3d(const Vecteur3D *v, const char *nom) { 
    printf("Vecteur %s = (%.2f, %.2f, %.2f)\n", nom, v->x, v->y, v->z);
}

// Fonction pour calculer le produit vectoriel de deux vecteurs 3D
Vecteur3D produit_vectoriel_3d(const Vecteur3D *v1, const Vecteur3D *v2) {
    Vecteur3D resultat;
    
    // Formule du produit vectoriel : v1 × v2
    resultat.x = v1->y * v2->z - v1->z * v2->y;
    resultat.y = v1->z * v2->x - v1->x * v2->z;
    resultat.z = v1->x * v2->y - v1->y * v2->x;
    
    return resultat;
}

// Fonction pour calculer le produit scalaire de deux vecteurs 3D
double produit_scalaire_3d(const Vecteur3D *v1, const Vecteur3D *v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

// === FONCTIONS POUR VECTEURS GÉNÉRAUX ===

// Fonction pour saisir un vecteur de taille variable
void saisir_vecteur(Vecteur *v) {
    printf("Entrez la taille du vecteur (max %d) : ", MAX_TAILLE);
    scanf("%d", &v->taille);
    
    if (v->taille > MAX_TAILLE) {
        printf("Taille trop grande, limitée à %d\n", MAX_TAILLE);
        v-> taille = MAX_TAILLE ;
    }
    
    if (v->taille <= 0) {
        printf("Taille invalide, fixée à 1\n");
        v->taille = 1;
    }
    
    printf("Saisie des composantes du vecteur :\n");
    for (int i = 0; i < v->taille; i++) {
        printf("Composante [%d] : ", i);
        scanf("%lf", &v->elements[i]);
    }
}

// Fonction pour afficher un vecteur
void afficher_vecteur(const Vecteur *v) {
    printf("Vecteur = (");
    for (int i = 0; i < v->taille; i++) {
        printf("%.2f", v->elements[i]);
        if (i < v->taille - 1) {
            printf(", ");
        }
    }
    printf(")\n");
}

// Fonction pour calculer le produit scalaire de deux vecteurs
double produit_scalaire(const Vecteur *v1, const Vecteur *v2) {
    if (v1->taille != v2->taille) {
        printf("Erreur : Les vecteurs doivent avoir la même taille!\n");
        return 0.0;
    }
    
    double resultat = 0.0;
    for (int i = 0; i < v1->taille; i++) {
        resultat += v1->elements[i] * v2->elements[i];
    }
    
    return resultat;
}

// === FONCTIONS POUR MATRICES ===

// Fonction pour saisir une matrice
void saisir_matrice(Matrice *m, int lignes, int colonnes) {
    m->lignes = lignes;
    m->colonnes = colonnes;
    
    printf("Saisie de la matrice %dx%d :\n", lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("Element [%d][%d] : ", i, j);
            scanf("%lf", &m->matrice[i][j]);
        }
    }
}

// Fonction pour afficher une matrice
void afficher_matrice(const Matrice *m) {
    printf("Matrice %dx%d :\n", m->lignes, m->colonnes);
    for (int i = 0; i < m->lignes; i++) {
        printf("[ ");
        for (int j = 0; j < m->colonnes; j++) {
            printf("%6.2f ", m->matrice[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

// Fonction pour vérifier la compatibilité vecteur × matrice
int compatible_vecteur_matrice(const Vecteur *v, const Matrice *m) {
    return (v->taille == m->lignes);
}

// Fonction pour calculer le produit vecteur × matrice
Vecteur produit_vecteur_matrice(const Vecteur *v, const Matrice *m) {
    Vecteur resultat;
    resultat.taille = m->colonnes;
    
    // Initialiser le résultat à 0
    for (int j = 0; j < m->colonnes; j++) {
        resultat.elements[j] = 0.0;
    }
    
    // Calculer le produit : vecteur ligne × matrice
    for (int j = 0; j < m->colonnes; j++) {
        for (int i = 0; i < v->taille; i++) {
            resultat.elements[j] += v->elements[i] * m->matrice[i][j];
        }
    }
    
    return resultat;
}