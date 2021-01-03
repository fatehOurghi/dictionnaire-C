#include<stdlib.h>
#include<ctype.h>
#include "../lib/outils.h"

char* auMinuscule(char* mot) {
	int len = strlen(mot);
	char* mot_min = (char*)malloc(sizeof(mot));
	for (int i = 0; i < len; i++)
	{
		mot_min[i] = tolower(mot[i]);
	}
	return mot_min;
}

int comparer(char* a, char* b){
	char* a_min = auMinuscule(a);
	char* b_min = auMinuscule(b);
    return strcmp(a_min, b_min);
}
