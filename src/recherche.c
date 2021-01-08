#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../lib/recherche.h"
#include "../lib/texte.h"
#define N_MAX 1000



ABR rechercher_mot(ABR arbre, char *mot)
{
    if (!arbre)
        return NULL;
    if (strcasecmp(arbre->mot, mot) > 0)
        return rechercher_mot(arbre->gauche, mot);
    else if (strcasecmp(arbre->mot, mot) < 0)
        return rechercher_mot(arbre->droit, mot);
    else
        return arbre;
}


void afficher_noeud(ABR e)
{
	printf("mot: \"%s\",  occurrence: %d\n", e->mot, e->occurrence);
    printf("Les lignes qui contient ce mot:\n");
	Liste p = e->lignes;
	while (p != NULL)
	{
		printf("%d,", p->ligne);
		p = p->suiv;
	}
	printf("\n-----------------------------------------------------------\n");
}

void rechecherSansArguments(Texte texte)
{
	srand(time(0));
	int debut = 0;
	int ligne = 1;
	int compteur = 0;
	while (1)
	{
		char *mot = lire_mot(texte, &debut, &ligne);
		if (compteur == N_MAX || mot == NULL)
			break;
		if (compteur < N_MAX && rand() % 2 == 1)
		{
			rechercher_mot(texte.A, mot);
			compteur++;
		}
	}
}

void rechercherMots(Texte texte, char *mots[], int taille)
{
	// 0: reservé au nom de programme(dico)
	// 1: reservé au nom de fichier(pg32469.txt)
	// 2 et superieur: reservés pour les mots à recherchés
	// ______________
	//           |
	for (int i = 2; i < taille; i++)
	{
		ABR mot = rechercher_mot(texte.A, mots[i]);
		if (mot)
			afficher_noeud(mot);
		else
		{
			printf("le mot \"%s\" n'existe pas dans le texte\n", mots[i]);
			printf("-----------------------------------------------------------\n");
		}
	}
}

