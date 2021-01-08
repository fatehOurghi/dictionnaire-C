#pragma once

#include <stdio.h>
#include "../lib/texte.h"

Texte lire_fichier(char *nom_fichier);
long taille_fichier(FILE * fichier);
int nombre_lignes(FILE *fichier);
