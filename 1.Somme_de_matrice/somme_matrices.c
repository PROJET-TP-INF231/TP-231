#include <stdio.h>
#include "somme_matrices.h"

void lireMatrice(int matrice[10][10], int lignes, int colonnes) {
    int i, j;
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
}

void additionnerMatrices(int matrice1[10][10], int matrice2[10][10], int resultat[10][10], int lignes, int colonnes) {
    int i, j;
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            resultat[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
}

void afficherMatrice(int matrice[10][10], int lignes, int colonnes) {
    int i, j;
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}
