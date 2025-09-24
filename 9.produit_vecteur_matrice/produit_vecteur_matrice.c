#include <stdio.h>
#include "produit_vecteur_matrice.h"

// ma fonction pour saisir un vecteur
void saisir_vecteur(Vecteur *v)
{
    printf("Entrez la taille du vecteur (max %d) : ", MAX_TAILLE);
    scanf("%d", &v->taille);

    if (v->taille > MAX_TAILLE)
    {
        printf("Taille trop grande, limitée à %d\n", MAX_TAILLE);
        v->taille = MAX_TAILLE;
    }

    if (v->taille <= 0)
    {
        printf("Taille invalide, fixée à 1\n");
        v->taille = 1;
    }

    printf("Saisie des composantes du vecteur :\n");
    for (int i = 0; i < v->taille; i++)
    {
        printf("Composante [%d] : ", i);
        scanf("%lf", &v->elements[i]);
    }
}

// Fonction pour afficher un vecteur
void afficher_vecteur(const Vecteur *v, const char *nom)
{
    printf("Vecteur %s = (", nom);
    for (int i = 0; i < v->taille; i++)
    {
        printf("%.2f", v->elements[i]);
        if (i < v->taille - 1)
        {
            printf(", ");
        }
    }
    printf(")\n");
}

// Fonction pour saisir une matrice
void saisir_matrice(Matrice *m, int lignes, int colonnes)
{
    m->lignes = lignes;
    m->colonnes = colonnes;

    printf("Saisie de la matrice %dx%d :\n", lignes, colonnes);
    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            printf("Element [%d][%d] : ", i, j);
            scanf("%lf", &m->matrice[i][j]);
        }
    }
}

// Fonction pour afficher une matrice
void afficher_matrice(const Matrice *m)
{
    printf("Matrice %dx%d :\n", m->lignes, m->colonnes);
    for (int i = 0; i < m->lignes; i++)
    {
        printf("[ ");
        for (int j = 0; j < m->colonnes; j++)
        {
            printf("%6.2f ", m->matrice[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

// Fonction pour vérifier la compatibilité vecteur × matrice
int compatible_vecteur_matrice(const Vecteur *v, const Matrice *m)
{
    return (v->taille == m->lignes);
}

// Fonction pour calculer le produit vecteur × matrice
Vecteur produit_vecteur_matrice(const Vecteur *v, const Matrice *m)
{
    Vecteur resultat;
    resultat.taille = m->colonnes;

    // Initialiser le résultat à 0
    for (int j = 0; j < m->colonnes; j++)
    {
        resultat.elements[j] = 0.0;
    }

    // Calculer le produit : vecteur ligne × matrice
    // Résultat[j] = Σ(vecteur[i] × matrice[i][j]) pour i de 0 à taille_vecteur-1
    for (int j = 0; j < m->colonnes; j++)
    {
        for (int i = 0; i < v->taille; i++)
        {
            resultat.elements[j] += v->elements[i] * m->matrice[i][j];
        }
    }

    return resultat;
}

// voici ma fonction pour montrer des exemples automatiques
void exemples_automatiques(void)
{
    printf("=== EXEMPLES AUTOMATIQUES ===\n\n");

    // Exemple 1 : Vecteur 1×2 × Matrice 2×3
    printf("--- Exemple 1 : Vecteur (1×2) × Matrice (2×3) ---\n");
    Vecteur v1 = {2, {1, 2}};
    Matrice m1 = {2, 3, {{1, 2, 3}, {4, 5, 6}}};

    afficher_vecteur(&v1, "v1");
    afficher_matrice(&m1);

    if (compatible_vecteur_matrice(&v1, &m1))
    {
        Vecteur resultat1 = produit_vecteur_matrice(&v1, &m1);
        afficher_vecteur(&resultat1, "résultat");
        printf("Calcul détaillé :\n");
        printf("  [1×1+2×4, 1×2+2×5, 1×3+2×6] = [9, 12, 15] ✓\n");
    }

    // Exemple 2 : Vecteur 1×3 × Matrice 3×2
    printf("\n--- Exemple 2 : Vecteur (1×3) × Matrice (3×2) ---\n");
    Vecteur v2 = {3, {2, 1, 3}};
    Matrice m2 = {3, 2, {{1, 4}, {2, 5}, {3, 6}}};

    afficher_vecteur(&v2, "v2");
    afficher_matrice(&m2);

    if (compatible_vecteur_matrice(&v2, &m2))
    {
        Vecteur resultat2 = produit_vecteur_matrice(&v2, &m2);
        afficher_vecteur(&resultat2, "résultat");
        printf("Calcul détaillé :\n");
        printf("  [2×1+1×2+3×3, 2×4+1×5+3×6] = [13, 31] ✓\n");
    }

    // Exemple 3 : Vecteur unitaire
    printf("\n--- Exemple 3 : Vecteur unitaire × Matrice identité ---\n");
    Vecteur v3 = {3, {1, 0, 0}};
    Matrice m3 = {3, 3, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};

    afficher_vecteur(&v3, "v3");
    printf("Matrice identité 3×3 :\n");
    afficher_matrice(&m3);

    if (compatible_vecteur_matrice(&v3, &m3))
    {
        Vecteur resultat3 = produit_vecteur_matrice(&v3, &m3);
        afficher_vecteur(&resultat3, "résultat");
        printf("Résultat attendu : (1, 0, 0) - première ligne de la matrice ✓\n");
    }
}