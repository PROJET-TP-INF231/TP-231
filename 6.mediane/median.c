#include <stdio.h>
#include <stdlib.h>

int comparer(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double trouverMedian(int tableau[], int taille) {
    if (taille == 0) {
        printf("Erreur : Tableau vide\n");
        return 0.0;
    }
    int *copie = (int*)malloc(taille * sizeof(int));
    for (int i = 0; i < taille; i++) {
        copie[i] = tableau[i];
    }
    qsort(copie, taille, sizeof(int), comparer);
    
    double median;
    
    if (taille % 2 == 1) {
        median = copie[taille / 2];
    } else {
        median = (copie[taille / 2 - 1] + copie[taille / 2]) / 2.0;
    }
    
    free(copie);
    return median;
}

double trouverMedianSansTri(int tableau[], int taille) {
    if (taille == 0) {
        printf("Erreur : Tableau vide\n");
        return 0.0;
    }
    
    int *copie = (int*)malloc(taille * sizeof(int));
    for (int i = 0; i < taille; i++) {
        copie[i] = tableau[i];
    }
    
    for (int i = 0; i < taille - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < taille; j++) {
            if (copie[j] < copie[minIndex]) {
                minIndex = j;
            }
        }
        int temp = copie[i];
        copie[i] = copie[minIndex];
        copie[minIndex] = temp;
    }
    
    double median;
    if (taille % 2 == 1) {
        median = copie[taille / 2];
    } else {
        median = (copie[taille / 2 - 1] + copie[taille / 2]) / 2.0;
    }
    
    free(copie);
    return median;
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
    
    int tableau1[] = {1, 3, 3, 6, 7, 8, 9};           
    int tableau2[] = {1, 2, 3, 4, 5, 6, 8, 9};       
    int tableau3[] = {5};                              
    int tableau4[] = {4, 2};                          
    int tableau5[] = {3, 1, 4, 2, 5};                 
    
    int taille1 = sizeof(tableau1) / sizeof(tableau1[0]);
    int taille2 = sizeof(tableau2) / sizeof(tableau2[0]);
    int taille3 = sizeof(tableau3) / sizeof(tableau3[0]);
    int taille4 = sizeof(tableau4) / sizeof(tableau4[0]);
    int taille5 = sizeof(tableau5) / sizeof(tableau5[0]);
    
    printf("Recherche du médian dans différents tableaux :\n\n");
    
    printf("Tableau 1 : ");
    afficherTableau(tableau1, taille1);
    printf(" -> Médian = %.1f\n", trouverMedian(tableau1, taille1));
    
    printf("Tableau 2 : ");
    afficherTableau(tableau2, taille2);
    printf(" -> Médian = %.1f\n", trouverMedian(tableau2, taille2));
    
    printf("Tableau 3 : ");
    afficherTableau(tableau3, taille3);
    printf(" -> Médian = %.1f\n", trouverMedian(tableau3, taille3));
    
    printf("Tableau 4 : ");
    afficherTableau(tableau4, taille4);
    printf(" -> Médian = %.1f\n", trouverMedian(tableau4, taille4));
    
    printf("Tableau 5 : ");
    afficherTableau(tableau5, taille5);
    printf(" -> Médian = %.1f\n", trouverMedian(tableau5, taille5));
    
    printf("\nAvec la version sans qsort :\n");
    printf("Tableau 5 : ");
    afficherTableau(tableau5, taille5);
    printf(" -> Médian = %.1f\n", trouverMedianSansTri(tableau5, taille5));
    
    return 0;
}