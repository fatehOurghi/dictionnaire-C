#pragma once

// la liste parcimonieuse qui contient les numéros de ligne d'un mot
typedef struct element
{
    int ligne;
    struct element *suiv;
} element;

typedef element *Liste;

Liste creer_liste(int debut);
void ajouter_element(Liste liste, int numero);
