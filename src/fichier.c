#include <stdlib.h>
#include "../lib/fichier.h"

int taille_fichier(FILE *fichier)
{
    fseek(fichier, 0L, SEEK_END);
    int taille = ftell(fichier);
    fseek(fichier, 0L, SEEK_SET);
    return taille;
}

int nombre_lignes(FILE *fichier)
{
    char c;
    int nombre = 0;
    while ((c = fgetc(fichier)) != EOF)
    {
        if (c == '\n')
        {
            nombre++;
        }
    }
    fseek(fichier, 0L, SEEK_SET);
    return nombre;
}

Texte lire_fichier(char *nom_fichier)
{
    FILE *fichier = fopen(nom_fichier, "r");
    Texte texte;
    texte.T = NULL;
    texte.L = NULL;
    texte.A = NULL;
    texte.nombre_char = 0;
    texte.nombre_lignes = 0;
    if (fichier != NULL)
    {
        int taille = taille_fichier(fichier);
        int n_lignes =  nombre_lignes(fichier);
        texte.nombre_char = taille;
        texte.nombre_lignes = n_lignes;
        texte.T = (char *)malloc(taille);
        texte.L = (int *)malloc(n_lignes);
        char c;
        int indice = 0;
        texte.L[0] = 0;
        int ligne = 1;
        while ((c = fgetc(fichier)) != EOF)
        {
            texte.T[indice++] = c;
            if (c == '\n')
            {
                texte.L[ligne++] = indice;
            }
        }
        fclose(fichier);
    }
    return texte;
}