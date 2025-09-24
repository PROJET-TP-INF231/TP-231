#include <stdio.h>
#include "multiplication_addition.h"

int main() {
    int a, b, resultat;
    int choix;
    
    printf("=== MULTIPLICATION PAR ADDITION (a × b avec +1 exclusivement) ===\n\n");
    
    // Tests automatiques
    test_multiplication();
    
    printf("\n=== MODE INTERACTIF ===\n");
    
    do {
        printf("\nEntrez la valeur de a (> 0) : ");
        scanf("%d", &a);
        
        printf("Entrez la valeur de b (> 0) : ");
        scanf("%d", &b);
        
        if (a <= 0 || b <= 0) {
            printf("Erreur : a et b doivent être strictement positifs!\n");
            continue;
        }
        
        printf("\nChoisissez la méthode :\n");
        printf("1. Méthode itérative\n");
        printf("2. Méthode récursive\n");
        printf("3. Les deux méthodes\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        printf("\n=== RÉSULTATS ===\n");
        
        switch (choix) {
            case 1:
                resultat = multiplication_par_addition(a, b);
                printf("%d × %d = %d (méthode itérative)\n", a, b, resultat);
                break;
                
            case 2:
                resultat = multiplication_recursive(a, b);
                printf("%d × %d = %d (méthode récursive)\n", a, b, resultat);
                break;
                
            case 3:
                printf("%d × %d = %d (méthode itérative)\n", a, b, multiplication_par_addition(a, b));
                printf("%d × %d = %d (méthode récursive)\n", a, b, multiplication_recursive(a, b));
                break;
                
            default:
                printf("Choix invalide!\n");
                continue;
        }
        
        printf("\nVoulez-vous continuer ? (1=Oui, 0=Non) : ");
        scanf("%d", &choix);
        
    } while (choix == 1);
    
    printf("Au revoir!\n");
    return 0;
}