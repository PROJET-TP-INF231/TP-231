#ifndef INVERSER_TABLEAU_H
#define INVERSER_TABLEAU_H

#define MAX_TAILLE 100

// fonctions  modeles
void saisir_tableau(int tableau[],int *taille);
void afficher_tableau(const int tableau[],int taille);
void inverser_tableau(int tableau[],int taille);
void inverser_avec_nouveau_tableau(const int source[], int destination[], int taille);
void copier_tableau(const int source[], 
    int destination[], int taille);

#endif