#pragma once
#include "liste.h"

typedef struct noeud
{
    char* mot;
    int occurrence;
    Liste lignes;
    int hauteur;
    struct noeud *parent;
    struct noeud *gauche;
    struct noeud *droit;
} noeud;
typedef noeud *ABR;




