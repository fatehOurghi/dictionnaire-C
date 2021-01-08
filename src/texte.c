#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/outils.h"
#include "../lib/texte.h"

char *lire_mot(Texte texte, int *debut, int *ligne)
{
    char *chaine = texte.T;
    long taille = texte.nombre_char;
    if (*debut < 0 || *debut >= taille || chaine == NULL)
        return NULL;

    int indice = *debut;
    char c = chaine[indice++];
    // tant que n'a pas de caractere trouvé en avance
    while (appartenir_alphabet(c) == 0 && indice < taille)
    {
        if (c == '\n')
            (*ligne)++;
        c = chaine[indice++];
    }

    // pas de mot trouvé dans la chaine
    if (indice >= taille)
        return NULL;

    // debut de mot trouvé
    char *mot = (char *)malloc(100 * sizeof(char));
    mot[0] = c;
    int i = 1;
    while (1)
    {
        if (appartenir_alphabet(c) == 1 && indice < taille)
        {
            c = chaine[indice++];
            mot[i++] = c;
        }
        else
        {
            if(c=='\n')
                indice--;
            break;
        }
    }
    mot[i - 1] = '\0';
    *debut = indice;
    return mot;
}

int appartenir_alphabet(char c)
{
    if (((int)c >= (int)'a' && (int)c <= (int)'z') || ((int)c >= (int)'A' && (int)c <= (int)'Z'))
        return 1;
    return 0;
}

Texte initialiser_texte()
{
    Texte texte;
    texte.A = NULL;
    texte.L = NULL;
    texte.T = NULL;
    texte.nombre_char = 0;
    texte.nombre_lignes = 0;
    return texte;
}

Texte remplir_texte(char *T, int *L, long n_car, int lignes)
{
    Texte texte;
    texte.A = NULL;
    texte.L = L;
    texte.T = T;
    texte.nombre_char = n_car;
    texte.nombre_lignes = lignes;
    return texte;
}
