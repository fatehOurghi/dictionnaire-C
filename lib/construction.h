#pragma once

#include <stdlib.h>
#include "arbre.h"

ABR cree_ABR(char *mot, int ligne);

int get_hauteur(ABR A);

void maj_Hauteur(ABR A);

int est_equilibreABR(ABR A);

int desequilibre(ABR A);

ABR rotationG(ABR A);

ABR rotationD(ABR A);

ABR rotationDG(ABR A);

ABR rotationGD(ABR A);

ABR reequilibrer(ABR A, ABR nouveau);

ABR creer_nouveau_noeud(char *mot, int occurrence, int pre_citation, int hauteur);

void maj_noeud(ABR e, int ligne);

ABR inserer_noeud(ABR A, ABR nouveau);
