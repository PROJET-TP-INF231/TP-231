#include <stdio.h>
#include "recherche_sequentielle.h"

// Fonction pour saisir un tableau
void saisir_tableau(int tableau[], int *taille) {
    printf("Entrez la taille du tableau (max %d) : ", MAX_TAILLE);
    scanf("%d", taille);
    
    if (*taille > MAX_TAILLE) {
        printf("Taille trop grande, limitée à %d\n", MAX_TAILLE);
        *taille = MAX_TAILLE;
    }
    
    printf("Saisie des éléments du tableau :\n");
    for (int i = 0; i < *taille; i++) {
        printf("Element [%d] : ", i);
        scanf("%d", &tableau[i]);
    }
}

// Fonction pour afficher un tableau
void afficher_tableau(const int tableau[], int taille) {
    printf("Tableau : [");
    for (int i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Fonction de recherche séquentielle (retourne la première position trouvée)
int recherche_sequentielle(const int tableau[], int taille, int element) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == element) {
            return i; // Retourne l'index de la première occurrence
        }
    }
    return -1; // Element non trouvé
}

// Fonction de recherche séquentielle (retourne toutes les positions)
int recherche_sequentielle_toutes_positions(const int tableau[], int taille, int element, int positions[]) {
    int nb_occurrences = 0;
    
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == element) {
            positions[nb_occurrences] = i;
            nb_occurrences++;
        }
    }
    
    return nb_occurrences;
}