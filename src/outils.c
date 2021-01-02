#include<stdlib.h>
#include "../lib/outils.h"

char* auMinuscule(char* mot) {
	int len = strlen(mot);
	char* mot_min = (char*)malloc(sizeof(mot));
	printf("%d", sizeof(mot));
	for (int i = 0; i < len; i++)
	{
		mot_min[i] = tolower(mot[i]);
	}
	return mot_min;
}