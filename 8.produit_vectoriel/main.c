
#include <stdio.h>
#include "produit_vectoriel.h"

void  menu_principal(void);
void test_produit_vectoriel_3d(void);
void    test_produit_scalaire(void);
void test_produit_vecteur_matrice(void);
void exemples_automatiques(void);

int main() {
    int choix;
    
    printf("=== PRODUITS VECTORIELS ET VECTEUR × MATRICE ===\n\n");
    
    do {
        menu_principal();
        scanf("%d", &choix);
        printf("\n");
        
        switch (choix) {
            case 1:
                test_produit_vectoriel_3d();
                break;
            case 2:
                test_produit_scalaire();
                break;
            case 3:
                test_produit_vecteur_matrice();
                break;
            case 4:
                exemples_automatiques();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
        
        if (choix != 0) {
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar(); 
            getchar(); 
        }
        
    } while (choix != 0);
    
    return 0;
}

void menu_principal(void) {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Produit vectoriel 3D (v1 × v2)\n");
    printf("2. Produit scalaire de vecteurs\n");
    printf("3. Produit vecteur × matrice\n");
    printf("4. Exemples automatiques\n");
    printf("0. Quitter\n");
    printf("Votre choix : ");
}

void test_produit_vectoriel_3d(void) {
    Vecteur3D v1, v2, resultat;
    
    printf("=== PRODUIT VECTORIEL 3D ===\n\n");
    
    saisir_vecteur3d(&v1, "v1");
    printf("\n");
    saisir_vecteur3d(&v2, "v2");
    
    printf("\n=== RÉSULTATS ===\n");
    afficher_vecteur3d(&v1, "v1");
    afficher_vecteur3d(&v2, "v2");
    
    // Produit vectoriel
    resultat = produit_vectoriel_3d(&v1, &v2);
    printf("\nProduit vectoriel v1 × v2 :\n");
    afficher_vecteur3d(&resultat, "v1×v2");
    
    // Produit scalaire pour information
    double scalaire = produit_scalaire_3d(&v1, &v2);
    printf("\nProduit scalaire v1 · v2 = %.2f\n", scalaire);
    
    // Vérification : le produit vectoriel est orthogonal aux deux vecteurs
    double verif1 = produit_scalaire_3d(&resultat, &v1);
    double verif2 = produit_scalaire_3d(&resultat, &v2);
    printf("\nVérification (doit être ≈ 0) :\n");
    printf("(v1×v2) · v1 = %.6f\n", verif1);
    printf("(v1×v2) · v2 = %.6f\n", verif2);
}

void test_produit_scalaire(void) {
    Vecteur v1, v2;
    
    printf("=== PRODUIT SCALAIRE DE VECTEURS ===\n\n");
    
    printf("--- Premier vecteur ---\n");
    saisir_vecteur(&v1);
    
    printf("\n--- Deuxième vecteur ---\n");
    saisir_vecteur(&v2);
    
    printf("\n=== RÉSULTATS ===\n");
    printf("Premier vecteur :\n");
    afficher_vecteur(&v1);
    
    printf("Deuxième vecteur :\n");
    afficher_vecteur(&v2);
    
    if (v1.taille == v2.taille) {
        double resultat = produit_scalaire(&v1, &v2);
        printf("\nProduit scalaire v1 · v2 = %.2f\n", resultat);
    } else {
        printf("\nErreur : Les vecteurs n'ont pas la même taille!\n");
        printf("Taille v1 : %d, Taille v2 : %d\n", v1.taille, v2.taille);
    }
}

void test_produit_vecteur_matrice(void) {
    Vecteur vecteur, resultat;
    Matrice matrice;
    int lignes, colonnes;
    
    printf("=== PRODUIT VECTEUR × MATRICE ===\n\n");
    
    printf("--- Saisie du vecteur ---\n");
    saisir_vecteur(&vecteur);
    
    printf("\n--- Saisie de la matrice ---\n");
    printf("Le vecteur a %d composantes.\n", vecteur.taille);
    printf("La matrice doit avoir %d lignes.\n", vecteur.taille);
    
    lignes = vecteur.taille;
    printf("Entrez le nombre de colonnes de la matrice : ");
    scanf("%d", &colonnes);
    
    if (lignes > MAX_TAILLE || colonnes > MAX_TAILLE) {
        printf("Erreur : Taille maximale dépassée (%d)\n", MAX_TAILLE);
        return;
    }
    
    saisir_matrice(&matrice, lignes, colonnes);
    
    printf("\n=== RÉSULTATS ===\n");
    printf("Vecteur :\n");
    afficher_vecteur(&vecteur);
    
    printf("Matrice :\n");
    afficher_matrice(&matrice);
    
    if (compatible_vecteur_matrice(&vecteur, &matrice)) {
        resultat = produit_vecteur_matrice(&vecteur, &matrice);
        printf("Produit vecteur × matrice :\n");
        afficher_vecteur(&resultat);
    } else {
        printf("Erreur : Vecteur et matrice incompatibles!\n");
    }
}

void exemples_automatiques(void) {
    printf("=== EXEMPLES AUTOMATIQUES ===\n\n");
    
    // Exemple 1 : Produit vectoriel 3D
    printf("--- Exemple 1 : Produit vectoriel 3D ---\n");
    Vecteur3D i = {1, 0, 0};
    Vecteur3D j = {0, 1, 0};
    Vecteur3D k = produit_vectoriel_3d(&i, &j);
    
    afficher_vecteur3d(&i, "i");
    afficher_vecteur3d(&j, "j");
    afficher_vecteur3d(&k, "i×j");
    printf("Résultat attendu : (0, 0, 1) ✓\n");
    
    // Exemple 2 : Produit scalaire
    printf("\n--- Exemple 2 : Produit scalaire ---\n");
    Vecteur v1 = {3, {1, 2, 3}};
    Vecteur v2 = {3, {4, 5, 6}};
    
    afficher_vecteur(&v1);
    afficher_vecteur(&v2);
    printf("Produit scalaire = %.2f\n", produit_scalaire(&v1, &v2));
    printf("Calcul : 1×4 + 2×5 + 3×6 = 4 + 10 + 18 = 32 ✓\n");
    
    // Exemple 3 : Vecteur × Matrice
    printf("\n--- Exemple 3 : Vecteur × Matrice ---\n");
    Vecteur v = {2, {1, 2}};
    Matrice m = {2, 3, {{1, 2, 3}, {4, 5, 6}}};
    
    printf("Vecteur :\n");
    afficher_vecteur(&v);
    printf("Matrice :\n");
    afficher_matrice(&m);
    
    Vecteur resultat = produit_vecteur_matrice(&v, &m);
    printf("Résultat :\n");
    afficher_vecteur(&resultat);
    printf("Calcul : [1×1+2×4, 1×2+2×5, 1×3+2×6] = [9, 12, 15] ✓\n");
}