#include <stdio.h>
#include "somme_matrices.h"

int main() {
    int lignes, colonnes;
    int matrice1[10][10], matrice2[10][10], somme[10][10];

    printf("Entrez le nombre de lignes et de colonnes des matrices: ");
    scanf("%d %d", &lignes, &colonnes);

    printf("Entrez les elements de la premiere matrice:\n");
    lireMatrice(matrice1, lignes, colonnes);

    printf("Entrez les elements de la deuxieme matrice:\n");
    lireMatrice(matrice2, lignes, colonnes);

    additionnerMatrices(matrice1, matrice2, somme, lignes, colonnes);

    printf("La somme des deux matrices est:\n");
    afficherMatrice(somme, lignes, colonnes);

    return 0;
}
