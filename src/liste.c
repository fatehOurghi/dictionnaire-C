#include <stdlib.h>
#include "../lib/liste.h"

Liste creer_liste(int debut)
{
    Liste liste = malloc(sizeof(Liste));
    liste->ligne = debut;
    liste->suiv = NULL;
    return liste;
}

void ajouter_element(Liste liste, int numero)
{
    if (liste == NULL)
    {
        liste = creer_liste(numero);
        return;
    }
    Liste e = malloc(sizeof(Liste));
    e->ligne = numero;
    e->suiv = NULL;
    Liste p = liste;
    while (p->suiv != NULL)
        p = p->suiv;

    p->suiv = e;
}
