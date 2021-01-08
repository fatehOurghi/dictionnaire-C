#pragma once

#include <stdlib.h>

#include "texte.h"
#include "arbre.h"
#include "recherche.h"
#include "fichier.h"
#include "liste.h"
#include "construction.h"
#include "outils.h"
#include "chrono.h"

ABR cree_ABR(char *mot, int ligne);

int get_hauteur(ABR A);

void maj_Hauteur(ABR A);

int desequilibre(ABR A);

ABR rotationGauche(ABR A);

ABR rotationDroite(ABR A);

ABR reequilibrer(ABR A, ABR nouveau);

ABR creer_nouveau_noeud(char *mot, int occurrence, int pre_citation, int hauteur);

void maj_noeud(ABR e, int ligne);

ABR inserer_noeud(ABR A, ABR nouveau);

Texte construirABR(char *nom_fichier, float* t_lire_fichier, float* t_construireABR);
