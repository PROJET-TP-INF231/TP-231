# Makefile pour le devoir de Structures de Données II
# Auteur: Groupe de TP - 6 membres

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
RM = rm -f

# Dossiers des exercices
DIRS = 1.somme_matrices 2.produit_matrices 3.recherche_sequentielle 4.multiplication_addition \
       5.tableau_trie 6.mediane 7.inverser_tableau 8.produit_vectoriel 9.produit_vecteur_matrice

# Règle par défaut
all: $(DIRS)

# Compilation de chaque exercice
1.somme_matrices:
	@echo "Compilation de l'exercice 1: Somme de matrices"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/somme_matrices.c

2.produit_matrices:
	@echo "Compilation de l'exercice 2: Produit de matrices"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/produit_matrices.c

3.recherche_sequentielle:
	@echo "Compilation de l'exercice 3: Recherche séquentielle"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/recherche_sequentielle.c

4.multiplication_addition:
	@echo "Compilation de l'exercice 4: Multiplication par addition"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/multiplication_addition.c

5.tableau_trie:
	@echo "Compilation de l'exercice 5: Tableau trié"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/tableau_trie.c

6.mediane:
	@echo "Compilation de l'exercice 6: Médiane"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/mediane.c

7.inverser_tableau:
	@echo "Compilation de l'exercice 7: Inverser tableau"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/inverser_tableau.c

8.produit_vectoriel:
	@echo "Compilation de l'exercice 8: Produit vectoriel"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/produit_vectoriel.c -lm

9.produit_vecteur_matrice:
	@echo "Compilation de l'exercice 9: Produit vecteur × matrice"
	$(CC) $(CFLAGS) -o $@/main $@/main.c $@/produit_vecteur_matrice.c

# Nettoyage
clean:
	@echo "Nettoyage des fichiers exécutables"
	@for dir in $(DIRS); do \
		$(RM) $$dir/main; \
	done

# Test de tous les exercices
test: all
	@echo "=== Tests de tous les exercices ==="
	@for dir in $(DIRS); do \
		echo "Test de $$dir:"; \
		echo "Exécutable créé: $$dir/main"; \
		echo ""; \
	done

# Aide
help:
	@echo "Makefile pour le devoir de Structures de Données II"
	@echo ""
	@echo "Commandes disponibles:"
	@echo "  make          - Compile tous les exercices"
	@echo "  make clean    - Supprime tous les exécutables"
	@echo "  make test     - Compile et vérifie tous les exercices"
	@echo "  make help     - Affiche cette aide"
	@echo ""
	@echo "Pour compiler un exercice spécifique:"
	@echo "  make 1.somme_matrices"
	@echo "  make 2.produit_matrices"
	@echo "  make 3.recherche_sequentielle"
	@echo "  make 4.multiplication_addition"
	@echo "  make 5.tableau_trie"
	@echo "  make 6.mediane"
	@echo "  make 7.inverser_tableau"
	@echo "  make 8.produit_vectoriel"
	@echo "  make 9.produit_vecteur_matrice"

.PHONY: all clean test help $(DIRS)