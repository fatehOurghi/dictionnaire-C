#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/outils.h"
#include "../lib/texte.h"

char *lire_mot(Texte texte, int *debut, int *ligne)
{
    char *chaine = texte.T;
    int taille = texte.nombre_char;
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
    char *mot = (char *)malloc(sizeof(char));
    mot[0] = '\0';
    while (appartenir_alphabet(c) == 1 && indice < taille)
    {
        strncat(mot, &c, 1);
        c = chaine[indice++];
        if (c == '\n')
            (*ligne)++;
    }
    *debut = indice;
    return mot;
}

int appartenir_alphabet(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}
