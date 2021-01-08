#include <stdio.h>
#include <string.h>

#include "../lib/construction.h"

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

int desequilibre(ABR A)
{
    if (A == NULL)
        return 0;
    return get_hauteur(A->gauche) - get_hauteur(A->droit);
}

ABR rotationDroite(ABR y)
{
    ABR x = y->gauche;
    ABR T2 = x->droit;

    // effectuer rotation
    x->droit = y;
    y->gauche = T2;

    //  mise à jour hauteur
    y->hauteur = max(get_hauteur(y->gauche), get_hauteur(y->droit)) + 1;
    x->hauteur = max(get_hauteur(x->gauche), get_hauteur(x->droit)) + 1;

    // Return nouveau racine
    return x;
}

ABR rotationGauche(ABR x)
{
    ABR y = x->droit;
    ABR T2 = y->gauche;

    // effectuer rotation
    y->gauche = x;
    x->droit = T2;

    //  mise à jour hauteur
    x->hauteur = max(get_hauteur(x->gauche), get_hauteur(x->droit)) + 1;
    y->hauteur = max(get_hauteur(y->gauche), get_hauteur(y->droit)) + 1;

    // Return nouveau racine
    return y;
}

ABR reequilibrer(ABR A, ABR nouveau)
{
    /* Obtenez le facteur d'équilibre de cet ancêtre
          nœud pour vérifier si ce nœud est devenu
          déséquilibré */
    int facteur = desequilibre(A);

    // cas: gauche gauche
    if (facteur > 1 && strcasecmp(A->gauche->mot, nouveau->mot) > 0)
        return rotationDroite(A);

    // cas: droit droit
    if (facteur < -1 && strcasecmp(A->droit->mot, nouveau->mot) < 0)
        return rotationGauche(A);

    // cas: gauche droit
    if (facteur > 1 && strcasecmp(A->gauche->mot, nouveau->mot) < 0)
    {
        A->gauche = rotationGauche(A->gauche);
        return rotationDroite(A);
    }

    // cas: droit gauche
    if (facteur < -1 && strcasecmp(A->droit->mot, nouveau->mot) > 0)
    {
        A->droit = rotationDroite(A->droit);
        return rotationGauche(A);
    }
    return A;
}

ABR creer_nouveau_noeud(char *mot, int occurrence, int ligne, int hauteur)
{
    ABR e = malloc(sizeof(noeud));
    e->droit = NULL;
    e->gauche = NULL;
    e->mot = mot;
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
        return nouveau;

    if (strcasecmp(A->mot, nouveau->mot) > 0)
        A->gauche = inserer_noeud(A->gauche, nouveau);
    else if (strcasecmp(A->mot, nouveau->mot) < 0)
        A->droit = inserer_noeud(A->droit, nouveau);
    else // mise à jour de l'occurrence de ce mot avec l'ajout de nouveau ligne
    {
        maj_noeud(A, nouveau->lignes->ligne);
        return A;
    }

    /* 2. Mettre à jour la hauteur de cet ancêtre nœud */
    A->hauteur = 1 + max(get_hauteur(A->gauche),
                         get_hauteur(A->droit));

    return reequilibrer(A, nouveau);
}

Texte construirABR(char *nom_fichier, float* t_lire_fichier, float* t_construireABR){
    chrono_reset();
    Texte texte = lire_fichier(nom_fichier);
    *t_lire_fichier = chrono_lap();

    chrono_reset();
	int debut = 0;
	int ligne = 1;
	char *premier = lire_mot(texte, &debut, &ligne);
	texte.A = cree_ABR(premier, ligne);
	while (1)
	{
		char *mot = lire_mot(texte, &debut, &ligne);
		if (mot == NULL)
			break;
		ABR e = creer_nouveau_noeud(mot, 1, ligne, 0);
		texte.A = inserer_noeud(texte.A, e);
	}
    *t_construireABR = chrono_lap();
    return texte;
}