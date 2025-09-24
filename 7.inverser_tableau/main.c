#include <stdio.h>
#include "inverser_tableau.h"

int main() {
    int tableau[MAX_TAILLE];
    int tableau_copie[MAX_TAILLE];
    int tableau_inverse[MAX_TAILLE];
    int taille;
    int choix, methode;
    
    printf("=== INVERSER UN TABLEAU ===\n\n");
    
    do {
        printf("--- Saisie du tableau ---\n");
        saisir_tableau(tableau, &taille);
        
        printf("\nTableau original :\n");
        afficher_tableau(tableau, taille);
        
        printf("\nChoisissez la méthode d'inversion :\n");
        printf("1. Inversion sur place (modifie le tableau original)\n");
        printf("2. Inversion avec nouveau tableau (garde l'original)\n");
        printf("3. Montrer les deux méthodes\n");
        printf("Votre choix : ");
        scanf("%d", &methode);
        
        printf("\n=== RÉSULTATS ===\n");
        
        switch (methode) {
            case 1:
                // Méthode 1 : Inversion sur place
                inverser_tableau(tableau, taille);
                printf("Tableau inversé (sur place) :\n");
                afficher_tableau(tableau, taille);
                break;
                
            case 2:
                // Méthode 2 : Nouveau tableau
                inverser_avec_nouveau_tableau(tableau, tableau_inverse, taille);
                printf("Tableau original (inchangé) :\n");
                afficher_tableau(tableau, taille);
                printf("Tableau inversé (nouveau) :\n");
                afficher_tableau(tableau_inverse, taille);
                break;
                
            case 3:
                // Montrer les deux méthodes
                printf("=== MÉTHODE 1 : Inversion sur place ===\n");
                copier_tableau(tableau, tableau_copie, taille);
                printf("Avant inversion :\n");
                afficher_tableau(tableau_copie, taille);
                inverser_tableau(tableau_copie, taille);
                printf("Après inversion :\n");
                afficher_tableau(tableau_copie, taille);
                
                printf("\n=== MÉTHODE 2 : Nouveau tableau ===\n");
                printf("Tableau original :\n");
                afficher_tableau(tableau, taille);
                inverser_avec_nouveau_tableau(tableau, tableau_inverse, taille);
                printf("Tableau inversé :\n");
                afficher_tableau(tableau_inverse, taille);
                break;
                
            default:
                printf("Choix invalide!\n");
                continue;
        }
        
        printf("\nVoulez-vous inverser un autre tableau ? (1=Oui, 0=Non) : ");
        scanf("%d", &choix);
        printf("\n");
        
    } while (choix == 1);
    
    // Exemples de test automatiques
    printf("=== EXEMPLES DE TEST ===\n");
    
    int test1[] = {1, 2, 3, 4, 5};
    int test2[] = {10, 20};
    int test3[] = {7};
    int test4[] = {1, 2, 3, 4};
    
    printf("\nTest 1 (5 éléments) :\n");
    printf("Original : ");
    afficher_tableau(test1, 5);
    inverser_tableau(test1, 5);
    printf("Inversé  : ");
    afficher_tableau(test1, 5);
    
    printf("\nTest 2 (2 éléments) :\n");
    printf("Original : ");
    afficher_tableau(test2, 2);
    inverser_tableau(test2, 2);
    printf("Inversé  : ");
    afficher_tableau(test2, 2);
    
    printf("\nTest 3 (1 élément) :\n");
    printf("Original : ");
    afficher_tableau(test3, 1);
    inverser_tableau(test3, 1);
    printf("Inversé  : ");
    afficher_tableau(test3, 1);
    
    printf("\nTest 4 (4 éléments) :\n");
    printf("Original : ");
    afficher_tableau(test4, 4);
    inverser_tableau(test4, 4);
    printf("Inversé  : ");
    afficher_tableau(test4, 4);
    
    return 0;
}
