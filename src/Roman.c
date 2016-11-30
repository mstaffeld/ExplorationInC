#include<stdio.h>
#include <string.h>
#include "Roman.h"

int isRoman(const char* characters)
{
	// Valid characters: I,V,X,L,C,D,M
	char* validCharacters = "IVXLCDM";

	for(int i = 0; i < strlen(characters); i++)
	{
		if(strchr(validCharacters, characters[i]) == NULL)
		{
			return 0;
		}
	}

	return 1;
}
