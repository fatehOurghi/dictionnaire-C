#include <stdio.h>
#include <stdlib.h>
#include "../lib/texte.h"
#include "../lib/recherche.h"
#include "../lib/fichier.h"
#include "../lib/liste.h"
#include "../lib/construction.h"
#include "../lib/outils.h"

#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;

	Texte texte = lire_fichier(argv[1]);
	int debut = 0;
	int ligne = 1;
	char *premier = lire_mot(texte, &debut, &ligne);
	texte.A = cree_ABR(premier, 1);

	while (debut < texte.nombre_char)
	{
		char *mot = lire_mot(texte, &debut, &ligne);
		ABR e = creer_nouveau_noeud(mot, 1, ligne, 0);

		inserer_noeud(texte.A, e);

		free(mot);
		//free(e);
		if (debut > 50)
			break;
	}

	ABR r = rechercher_mot(texte.A, "project");
	if (r)
		printf("%d\n", r->occurrence);

	return 0;
}