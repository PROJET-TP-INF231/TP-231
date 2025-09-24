#include <stdio.h>
#include "multiplication_addition.h"

// Fonction pour calculer a × b en utilisant exclusivement +1 (méthode itérative)
int multiplication_par_addition(int a, int b)
{
    // Vérification que a et b sont positifs
    if (a <= 0 || b <= 0)
    {
        printf("Erreur : a et b doivent être strictement positifs\n");
        return 0;
    }

    int resultat = 0;
    int compteur_a = 0;

    // Nous allons additionner b exactement a fois
    while (compteur_a < a)
    {
        int compteur_b = 0;
        // Ajouter b au résultat (en utilisant +1)
        while (compteur_b < b)
        {
            resultat = resultat + 1;
            compteur_b = compteur_b + 1;
        }
        compteur_a = compteur_a + 1;
    }

    return resultat;
}

// Version récursive alternative
int multiplication_recursive(int a, int b)
{
    // Vérification que a et b sont positifs
    if (a <= 0 || b <= 0)
    {
        return 0;
    }

    // Cas de base
    if (a == 1)
    {
        return b;
    }

    // Appel récursif : a × b = b + (a-1) × b
    return b + multiplication_recursive(a - 1, b);
}

// Fonction de test pour démontrer le fonctionnement
void test_multiplication(void)
{
    printf("=== TESTS DE MULTIPLICATION ===\n");

    int test_cases[][2] = {
        {2, 3}, {4, 5}, {1, 7}, {3, 1}, {6, 4}};

    int nb_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < nb_tests; i++)
    {
        int a = test_cases[i][0];
        int b = test_cases[i][1];
        int resultat_iteratif = multiplication_par_addition(a, b);
        int resultat_recursif = multiplication_recursive(a, b);

        printf("%d × %d = %d (itératif) = %d (récursif)\n",
               a, b, resultat_iteratif, resultat_recursif);
    }
}