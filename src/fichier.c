#include <stdlib.h>
#include "../lib/fichier.h"
#include "../lib/texte.h"

long taille_fichier(FILE *fichier)
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
    FILE *file = fopen(nom_fichier, "r");
    Texte texte = initialiser_texte();
    char *T;
    int *L;
    int n = 0;
    int c;
    int ligne = 0;
    //On ne peut pas ouvrir le fichier, alors retourner texte vide
    if (file == NULL)
    {
        printf("On ne peut pas ouvrir le fichier, \"%s\" fichier introuvable", nom_fichier);
        exit(1);
    }

    long taille_fic = taille_fichier(file);
    int lignes = nombre_lignes(file);
    T = malloc(taille_fic);
    L = malloc(lignes * sizeof(int));
    L[0] = 0;

    while ((c = fgetc(file)) != EOF)
    {
        T[n++] = (char)c;
        if ((char)c == '\n')
            L[++ligne] = n;
    }

    T[n] = '\0';
    texte = remplir_texte(T, L, taille_fic, lignes);
    return texte;
}