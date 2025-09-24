# 🔢 Algorithmes en C – Tableaux et Matrices

Ce projet contient plusieurs programmes en langage **C** qui implémentent des algorithmes classiques sur les **tableaux** et les **matrices**.

## 📁 Contenu du projet

| Fichier | Description |
|--------|-------------|
| `somme_matrices.c` | Addition de deux matrices |
| `produit_matrices.c` | Multiplication de deux matrices |
| `recherche_sequentielle.c` | Recherche d’un élément dans un tableau (recherche séquentielle) |
| `test_tableau_trie.c` | Vérifie si un tableau est trié dans l’ordre croissant |
| `mediane_tableau.c` | Calcule la médiane d’un tableau |
| `inverser_tableau.c` | Inverse les éléments d’un tableau |
| `produit_vectoriel.c` | Calcule le produit vectoriel de deux vecteurs 3D |
| `vecteur_matrice.c` | Calcule le produit d’un vecteur ligne par une matrice |

## 🛠️ Compilation

Pour compiler un fichier source, utilisez `gcc` :

```bash
gcc -o programme nom_du_fichier.c
./programme
Par exemple, pour compiler et exécuter le programme de somme de matrices:
gcc -o somme somme_matrices.c
./somme
Exemple d’exécution:
=== Somme de Matrices ===
Entrez les dimensions (lignes colonnes): 2 2
Entrez les éléments de la première matrice:
1 2
3 4
Entrez les éléments de la deuxième matrice:
5 6
7 8

Résultat:
6 8
10 12
