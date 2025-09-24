#include <stdio.h>
#include "produit_vecteur_matrice.h"

int main()
{
    Vecteur vecteur, resultat;
    Matrice matrice;
    int lignes, colonnes;
    int choix;

    printf("=== PRODUIT VECTEUR × MATRICE ===\n\n");

    do
    {
        printf("=== MENU PRINCIPAL ===\n");
        printf("1. Calculer un produit vecteur × matrice\n");
        printf("2. Voir les exemples automatiques\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix)
        {
        case 1:
            printf("--- Calcul interactif ---\n");

            // Saisie du vecteur
            printf("--- Saisie du vecteur ---\n");
            saisir_vecteur(&vecteur);

            // Saisie de la matrice
            printf("\n--- Saisie de la matrice ---\n");
            printf("Le vecteur a %d composantes.\n", vecteur.taille);
            printf("La matrice doit avoir %d lignes pour être compatible.\n", vecteur.taille);

            lignes = vecteur.taille;
            printf("Entrez le nombre de colonnes de la matrice : ");
            scanf("%d", &colonnes);

            if (lignes > MAX_TAILLE || colonnes > MAX_TAILLE)
            {
                printf("Erreur : Taille maximale dépassée (%d)\n", MAX_TAILLE);
                break;
            }

            saisir_matrice(&matrice, lignes, colonnes);

            // affichage et calcul
            printf("\n=== RÉSULTATS ===\n");
            printf("Vecteur d'entrée :\n");
            afficher_vecteur(&vecteur, "v");

            printf("Matrice d'entrée :\n");
            afficher_matrice(&matrice);

            if (compatible_vecteur_matrice(&vecteur, &matrice))
            {
                resultat = produit_vecteur_matrice(&vecteur, &matrice);
                printf("Produit vecteur × matrice :\n");
                afficher_vecteur(&resultat, "v×M");

                // quel que detail  du calcul
                printf("\nExplication du calcul :\n");
                printf("Pour chaque colonne j de la matrice :\n");
                printf("  résultat[j] = Σ(vecteur[i] × matrice[i][j])\n");
                printf("  où i va de 0 à %d\n", vecteur.taille - 1);
            }
            else
            {
                printf("Erreur : Vecteur et matrice incompatibles!\n");
                printf("Le vecteur a %d composantes, mais la matrice a %d lignes.\n",
                       vecteur.taille, matrice.lignes);
            }
            break;

        case 2:
            exemples_automatiques();
            break;

        case 0:
            printf("Au revoir!\n");
            break;

        default:
            printf("Choix invalide!\n");
        }

        if (choix != 0)
        {
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar();
            getchar();
            printf("\n");
        }

    } while (choix != 0);

    return 0;
}