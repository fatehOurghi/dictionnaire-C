#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/recherche.h"




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
