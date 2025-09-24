#ifndef RECHERCHE_SEQUENTIELLE_H
#define RECHERCHE_SEQUENTIELLE_H

#define MAX_TAILLE 100

// Prototypes des fonctions
void saisir_tableau(int tableau[], int *taille);
void afficher_tableau(const int tableau[], int taille);
int recherche_sequentielle(const int tableau[], int taille, int element);
int recherche_sequentielle_toutes_positions(const int tableau[], int taille, int element, int positions[]);

#endif