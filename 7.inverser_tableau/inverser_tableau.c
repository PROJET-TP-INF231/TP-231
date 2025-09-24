#include <stdio.h>
 #include "inverser_tableau.h"



 void saisir_tableau(int tableau[], int *taille) {
    printf("Entrez la taille du tableau (max %d) : ", MAX_TAILLE);
    scanf("%d",taille);
    
    if (*taille > MAX_TAILLE) {
        printf("Taille trop grande, limitée à %d\n", MAX_TAILLE);
        *taille = MAX_TAILLE;
    }
    
    if (*taille <= 0) {
        printf("Taille invalide, fixée à 1\n");
        *taille = 1;
    }
    
    printf("Saisie des éléments du tableau :\n");
    for (int i = 0; i < *taille; i++) {
        printf("Element [%d] : ", i);
        scanf("%d", &tableau[i]);
    }
}

//  pour afficher, un tableau

void afficher_tableau(const int tableau[], int taille) {
    printf("Tableau : [");
    for (int i = 0; <taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille-1) {
            printf(",");
        }
    }
    printf("]\n");
}

// copier un tableau

void copier_tableau(const int source[], int destination[], int taille) {
    for (int i=0; i<taille; i++) {
        destination[i] = source[i];
    }
}

// inverser un tableau u u

void inverser_tableau(int tableau[], int taille) {
    int debut =0;
    int fin =taille-1;
    
    while (debut < fin) {
        // Échanger les éléments debut et fin.
        int temp=tableau[debut];
        tableau[debut]=tableau[fin];
        tableau[fin] = temp;
        debut++;
        fin--;
    }
}

// inverser avec un nouveau tableau
void inverser_avec_nouveau_tableau(const int source[], int destination[], int taille) {
    for (int i=0 ; i<taille ; i++) {
        destination[i] = source[taille-1-i];
    }
}
