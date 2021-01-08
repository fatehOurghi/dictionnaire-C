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

void parcourInfixe(ABR arbre)
{
    if (arbre == NULL)
        return;
    parcourInfixe(arbre->gauche);
    printf("mot = %s, \t\toccurrence = %d,\t hauteur= %d\n", arbre->mot, arbre->occurrence, arbre->hauteur);
    parcourInfixe(arbre->droit);
}