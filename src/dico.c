#include <stdio.h>
#include <stdlib.h>
#include "../lib/texte.h"
#include "../lib/recherche.h"
#include "../lib/fichier.h"
#include <string.h>


int main(int argc, char * argv[]) 
{ 
	if (argc < 2) return 1; 
	
	Texte t = lire_fichier(argv[1]);
	for(int i = 0;i<t.nombre_char;i++){
		printf("%c\n", t.T[i]);
	}
	return 0; 
} 