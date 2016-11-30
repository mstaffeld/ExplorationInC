#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "Roman.h"

int getValue(const char* romanNumeral)
{
	if (strcmp(romanNumeral, "I") == 0)
		return 1;

	return -1;
}

int isRoman(const char* characters)
{
	char* validCharacters = "IVXLCDM";

	for(int i = 0; i < strlen(characters); i++)
	{
		if(strchr(validCharacters, toupper(characters[i])) == NULL)
		{
			return 0;
		}
	}

	return 1;
}
