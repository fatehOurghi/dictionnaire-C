#pragma once
#include "arbre.h"

typedef struct Texte{
    char* T;
    int* L;
    ABR A;
    long nombre_char;
    int nombre_lignes;
}Texte;

char* lire_mot(Texte texte, int *debut, int *ligne);

int appartenir_alphabet(char c);

Texte initialiser_texte();

Texte remplir_texte(char* T, int*L, long n_car, int lignes);