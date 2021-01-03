#include<stdio.h>
#include "../lib/construction.h"
#include "../lib/outils.h"

// creer la racine de l'arbre
ABR cree_ABR(char *mot, int ligne)
{
    ABR A = malloc(sizeof(noeud));
    A->droit = NULL;
    A->gauche = NULL;
    A->mot = mot;
    A->lignes = creer_liste(ligne);
    A->occurrence = 1;
    A->hauteur = 0;
    return A;
}

int get_hauteur(ABR A)
{
    if (A == NULL)
        return -1;
    return A->hauteur;
}

void maj_Hauteur(ABR A)
{
    if (A != NULL)
    {
        if (A->droit == NULL && A->gauche == NULL)
        {
            A->hauteur = 0;
        }
        if (A->gauche != NULL && A->droit != NULL)
            A->hauteur = 1 + max(A->gauche->hauteur, A->droit->hauteur);
        else if (A->gauche != NULL && A->droit == NULL)
            A->hauteur = 1 + A->gauche->hauteur;
        else if (A->droit != NULL && A->gauche == NULL)
            A->hauteur = 1 + A->droit->hauteur;
    }
}

int est_equilibreABR(ABR A)
{
    if (A == NULL)
    {
        return 1;
    }
    else
    {
        if (abs(get_hauteur(A->gauche) - get_hauteur(A->droit)) > 1)
            return 0;
        return est_equilibreABR(A->gauche) && est_equilibreABR(A->droit);
    }
}

int desequilibre(ABR A)
{
    if (A == NULL)
        return 0;
    return (get_hauteur(A->gauche) - get_hauteur(A->droit));
}

void rotationG(ABR A)
{
    if (A != NULL)
    {
        if (A->gauche != NULL)
        {
            ABR B = A->gauche;
            A->gauche = B->droit;
            B->droit = A;
            A = B;
            maj_Hauteur(A->droit);
            maj_Hauteur(A);
        }
    }
}

void rotationD(ABR A)
{
    if (A != NULL)
    {
        if (A->droit != NULL)
        {
            ABR B = A->droit;
            A->droit = B->gauche;
            B->gauche = A;
            A = B;
            maj_Hauteur(A->gauche);
            maj_Hauteur(A);
        }
    }
}

void rotationDG(ABR A)
{
    if (A != NULL)
        if (A->droit != NULL)
        {
            rotationD(A->droit);
            rotationG(A);
        }
}

void rotationGD(ABR A)
{
    if (A != NULL)
        if (A->gauche != NULL)
        {
            rotationG(A->droit);
            rotationD(A);
        }
}

void reequilibrer(ABR A)
{
    if (A != NULL)
    {
        int d = desequilibre(A);

        if (d == 2)
        {
            d = desequilibre(A->gauche);
            if (d == 1)
            {
                rotationD(A);
            }
            else if (d == -1)
            {
                rotationGD(A);
            }
        }
        else if (d == -2)
        {
            d = desequilibre(A->gauche);
            if (d == 1)
            {
                rotationG(A);
            }
            else if (d == -1)
            {
                rotationDG(A);
            }
        }
    }
}

ABR creer_nouveau_noeud(char *mot, int occurrence, int ligne, int hauteur)
{
    ABR e = malloc(sizeof(noeud));
    e->droit = NULL;
    e->gauche = NULL;
    e->mot = malloc(strlen(mot));
    strcpy(e->mot, mot);
    e->lignes = creer_liste(ligne);
    e->occurrence = occurrence;
    e->hauteur = hauteur;
    return e;
}

void maj_noeud(ABR e, int ligne)
{
    e->occurrence++;
    ajouter_element(e->lignes, ligne);
}

ABR inserer_noeud(ABR A, ABR nouveau)
{
    /* 1. Effectuer l'insertion ABR normale */
    if (A == NULL)
    {
        return nouveau;
    }
    if (comparer(A->mot, nouveau->mot) > 0)
        A->gauche = inserer_noeud(A->gauche, nouveau);
    else if (comparer(A->mot, nouveau->mot) < 0)
        A->droit = inserer_noeud(A->droit, nouveau);
    else // Egale
    { 
        maj_noeud(A, nouveau->lignes[0].ligne);
        return A;
    }
    /* 2. Mettre à jour la hauteur de ce nœud ancêtre */
    maj_Hauteur(A);

    reequilibrer(A);

    return A;
}
