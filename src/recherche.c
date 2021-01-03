#include <stdlib.h>
#include <stdio.h>
#include "../lib/recherche.h"
#include "../lib/outils.h"

ABR rechercher_mot(ABR arbre, char *mot)
{
    if (!arbre)
        return NULL;
    if (comparer(arbre->mot, mot) > 0)
        return rechercher_mot(arbre->gauche, mot);
    else if (comparer(arbre->mot, mot) < 0)
        return rechercher_mot(arbre->droit, mot);
    else
        return arbre;
}