#pragma once

#include <stdlib.h>
#include "arbre.h"

ABR cree_ABR(char *mot, int ligne);

int get_hauteur(ABR A);

void maj_Hauteur(ABR A);

int est_equilibreABR(ABR A);

int desequilibre(ABR A);

void rotationG(ABR A);

void rotationD(ABR A);

void rotationDG(ABR A);

void rotationGD(ABR A);

void reequilibrer(ABR A);

ABR creer_nouveau_noeud(char *mot, int occurence, int pre_citation, int hauteur);

void maj_noeud(ABR e, int ligne);

void inserer_noeud(ABR A, ABR nouveau);
