#include <stdio.h>
#include "produit_matrices.h"

int main() {
    int lignes1, colonnes1, lignes2, colonnes2;
    int matrice1[10][10], matrice2[10][10], produit[10][10];

    printf("Entrez le nombre de lignes et de colonnes de la premiere matrice: ");
    scanf("%d %d", &lignes1, &colonnes1);

    printf("Entrez les elements de la premiere matrice:\n");
    lireMatrice(matrice1, lignes1, colonnes1);

    printf("Entrez le nombre de lignes et de colonnes de la deuxieme matrice: ");
    scanf("%d %d", &lignes2, &colonnes2);

    if (colonnes1 != lignes2) {
        printf("Erreur: Le nombre de colonnes de la premiere matrice doit etre egal au nombre de lignes de la deuxieme.\n");
        return 1;
    }

    printf("Entrez les elements de la deuxieme matrice:\n");
    lireMatrice(matrice2, lignes2, colonnes2);

    multiplierMatrices(matrice1, matrice2, produit, lignes1, colonnes1, colonnes2);

    printf("Le produit des deux matrices est:\n");
    afficherMatrice(produit, lignes1, colonnes2);

    return 0;
}
