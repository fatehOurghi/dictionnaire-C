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
/*
Texte lire_fichier(char *nom_fichier)
{
    FILE *fichier = fopen(nom_fichier, "r");
    Texte texte = initialiser_texte();
    if (fichier != NULL)
    {
        long taille = taille_fichier(fichier);
        int n_lignes = nombre_lignes(fichier);
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
}*/


Texte lire_fichier(char *fileName)
{
	FILE *file = fopen(fileName, "r");
	Texte texte = initialiser_texte();
	char *T;
    int *L;
	int n = 0;
	int c;
    int ligne = 0;
	//On ne peut pas ouvrir le fichier, alors retourner texte vide
	if (file == NULL)
		return texte;

	long f_size = taille_fichier(file);
    int lignes = nombre_lignes(file);
	T = malloc(f_size);
    L = malloc(lignes*sizeof(int));
    L[0] = 0;
    
	while ((c = fgetc(file)) != EOF)
	{
		T[n++] = (char)c;
		if ((char)c == '\n')
            L[++ligne] = n;
	}

	T[n] = '\0';
    texte = remplir_texte(T, L, f_size, lignes);
	return texte;
}