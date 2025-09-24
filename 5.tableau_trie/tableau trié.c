#include <stdio.h>
#include <stdbool.h>

bool estTableauTrie(int tableau[], int taille) {
    if (taille <= 1) {
        return true;
    }
    for (int i = 0; i < taille - 1; i++) {
        if (tableau[i] > tableau[i + 1]) {
            return false; 
        }
    }
    
    return true; 
}

int testTriTableau(int tableau[], int taille) {
    if (taille <= 1) {
        return 1; 
    }
    
    bool croissant = true;
    bool decroissant = true;
    
    for (int i = 0; i < taille - 1; i++) {
        if (tableau[i] > tableau[i + 1]) {
            croissant = false;
        }
        if (tableau[i] < tableau[i + 1]) {
            decroissant = false;
        }
    }
    
    if (croissant) return 1;      
    if (decroissant) return -1;   
    return 0;                     
}

void afficherTableau(int tableau[], int taille) {
    printf("[");
    for (int i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) printf(", ");
    }
    printf("]");
}

int main() {
    int tableau1[] = {1, 2, 3, 4, 5};     
    int tableau2[] = {5, 4, 3, 2, 1};     
    int tableau3[] = {1, 3, 2, 5, 4};     
    int tableau4[] = {7};                 
    
    int taille1 = sizeof(tableau1) / sizeof(tableau1[0]);
    int taille2 = sizeof(tableau2) / sizeof(tableau2[0]);
    int taille3 = sizeof(tableau3) / sizeof(tableau3[0]);
    int taille4 = sizeof(tableau4) / sizeof(tableau4[0]);
    
    printf("Test de la fonction estTableauTrie :\n");
    
    printf("Tableau 1 : ");
    afficherTableau(tableau1, taille1);
    printf(" -> %s\n", estTableauTrie(tableau1, taille1) ? "Trié" : "Non trié");
    
    printf("Tableau 2 : ");
    afficherTableau(tableau2, taille2);
    printf(" -> %s\n", estTableauTrie(tableau2, taille2) ? "Trié" : "Non trié");
    
    printf("Tableau 3 : ");
    afficherTableau(tableau3, taille3);
    printf(" -> %s\n", estTableauTrie(tableau3, taille3) ? "Trié" : "Non trié");
    
    printf("\nTest de la fonction testTriTableau :\n");
    
    int resultat;
    resultat = testTriTableau(tableau1, taille1);
    printf("Tableau 1 -> ");
    switch(resultat) {
        case 1: printf("Trié croissant\n"); break;
        case -1: printf("Trié décroissant\n"); break;
        case 0: printf("Non trié\n"); break;
    }
    
    resultat = testTriTableau(tableau2, taille2);
    printf("Tableau 2 -> ");
    switch(resultat) {
        case 1: printf("Trié croissant\n"); break;
        case -1: printf("Trié décroissant\n"); break;
        case 0: printf("Non trié\n"); break;
    }
    
    resultat = testTriTableau(tableau3, taille3);
    printf("Tableau 3 -> ");
    switch(resultat) {
        case 1: printf("Trié croissant\n"); break;
        case -1: printf("Trié décroissant\n"); break;
        case 0: printf("Non trié\n"); break;
    }
    
    return 0;
}