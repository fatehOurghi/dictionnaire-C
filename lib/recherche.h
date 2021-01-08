#pragma once
#include "arbre.h"

ABR rechercher_mot(ABR arbre, char *mot);

void parcourInfixe(ABR arbre);

void afficher_noeud(ABR e);

void rechecherSansArguments(Texte texte);

void rechercherMots(Texte texte, char *mots[], int taille);

