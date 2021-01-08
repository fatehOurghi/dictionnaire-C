#include <stdio.h>
#include <stdlib.h>
#include "../lib/texte.h"
#include "../lib/recherche.h"
#include "../lib/fichier.h"
#include "../lib/liste.h"
#include "../lib/construction.h"

#include <string.h>

void afficher_noeud(ABR e)
{
	printf("mot= \"%s\",  occurrence= %d\n", e->mot, e->occurrence);

	Liste p = e->lignes;
	while (p != NULL)
	{
		printf("ligne= %d\n", p->ligne);
		p = p->suiv;
	}
	printf("-------------------\n");
}

void affiche_arbre(ABR a, int niveau)
{
	char* v; 
	int i;
	ABR g, d;
	if (a != NULL)
	{
		g = a->gauche;
		affiche_arbre(g, niveau + 1);
		v = a->mot;
		for (i = 0; i < niveau; i++)
			printf("\t\t");
		printf("%s\n", v);
		d = a->droit;
		affiche_arbre(d, niveau + 1);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;

	Texte texte = lire_fichier(argv[1]);
	int debut = 0;
	int ligne = 1;
	char *premier = lire_mot(texte, &debut, &ligne);
	printf("------------------------\n");
	texte.A = cree_ABR(premier, ligne);
	//afficher_noeud(texte.A);
	while (1)
	{
		char *mot = lire_mot(texte, &debut, &ligne);
		if (mot == NULL)
			break;
		ABR e = creer_nouveau_noeud(mot, 1, ligne, 0);
		//printf("insertion de: %s\n ", mot);
		texte.A = inserer_noeud(texte.A, e);
	}

	ABR r = rechercher_mot(texte.A, "project");
	if (r)
		printf("%d\n", r->occurrence);

	parcourInfixe(texte.A);
	affiche_arbre(texte.A,0);
	//afficher_noeud(texte.A);
	return 0;
}
