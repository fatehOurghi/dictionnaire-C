#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/construction.h"
#include "../lib/chrono.h"


int main(int argc, char *argv[])
{

	float t_lire_fichier, t_construireABR, t_recherche, t_mile_rech, t_total;
	// au moins le nom fichier existe devant le nom du programme(comme ./dico pg31469.txt)
	if (argc < 2)
		return 1;

	chrono_reset();
	Texte texte = construirABR(argv[1], &t_lire_fichier, &t_construireABR);
	t_construireABR = chrono_lap();
	
	// il existe des mots à rechercher dans le texte.
	if (argc > 2)
	{
		chrono_reset();
		rechercherMots(texte, argv, argc);
		t_recherche = chrono_lap();
		printf("temps de lire le fichier: %.6lf\n", t_lire_fichier);
		printf("temps de construcion de l'ABR est: %.6lf\n", t_construireABR);
		printf("temps de recherche est: %.6lf\n", t_recherche);
		t_total = t_lire_fichier + t_construireABR + t_recherche;
	}
	// il n'existe pas des mots à rechercher dans le texte.(argc==2)
	else
	{
		chrono_reset();
		rechecherSansArguments(texte);
		t_mile_rech = chrono_lap();
		printf("temps de lire le fichier: %.6lf microsecondes\n", t_lire_fichier);
		printf("temps de construcion de l'ABR est: %.6lf microsecondes\n", t_construireABR);
		printf("temps de recherche sans mots fournis en entree (1000 recherches de mots aleatoires) est: %.6lf microsecondes\n", t_mile_rech);
		t_total = t_lire_fichier + t_construireABR + t_mile_rech;
	}
	printf("temps total d'execution est: %.6lf microsecondes\n", t_total);

	return 0;
}
