#include <stdio.h>
#include "recherche_sequentielle.h"

int main() {
    int tableau[MAX_TAILLE];
    int positions[MAX_TAILLE];
    int taille, element, position, nb_occurrences;
    
    printf("=== RECHERCHE SÉQUENTIELLE DANS UN TABLEAU ===\n\n");
    
    // Saisie du tableau
    saisir_tableau(tableau, &taille);
    
    printf("\n");
    afficher_tableau(tableau, taille);
    
    printf("\nEntrez l'élément à rechercher : ");
    scanf("%d", &element);
    
    // Recherche de la première occurrence
    position = recherche_sequentielle(tableau, taille, element);
    
    printf("\n=== RÉSULTATS ===\n");
    if (position != -1) {
        printf("Élément %d trouvé à la position %d (première occurrence)\n", element, position);
    } else {
        printf("Élément %d non trouvé dans le tableau\n", element);
    }
    
    // Recherche de toutes les occurrences
    nb_occurrences = recherche_sequentielle_toutes_positions(tableau, taille, element, positions);
    
    if (nb_occurrences > 0) {
        printf("Nombre total d'occurrences : %d\n", nb_occurrences);
        printf("Positions : ");
        for (int i = 0; i < nb_occurrences; i++) {
            printf("%d", positions[i]);
            if (i < nb_occurrences - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
    
    return 0;
}