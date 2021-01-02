#pragma once

typedef struct noeud
{
    int occurrence;
    struct noeud *parent;
    struct noeud *gauche;
    struct noeud *droit;
} noeud;
typedef noeud *ABR;




