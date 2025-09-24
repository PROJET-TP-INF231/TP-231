#include <stdio.h>
#include "produit_matrices.h"

void lireMatrice(int matrice[10][10], int lignes, int colonnes) {
    int i, j;
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
}

void multiplierMatrices(int matrice1[10][10], int matrice2[10][10], int resultat[10][10], int lignes1, int colonnes1, int colonnes2) {
    int i, j, k;
    for (i = 0; i < lignes1; i++) {
        for (j = 0; j < colonnes2; j++) {
            resultat[i][j] = 0;
            for (k = 0; k < colonnes1; k++) {
                resultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
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
