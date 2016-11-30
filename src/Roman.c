#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "Roman.h"

int getValue(const char* romanNumeral)
{
	//TODO: make better
	if (strcmp(romanNumeral, "I") == 0)
		return 1;
	
	if (strcmp(romanNumeral, "V") == 0)                 
		return 5;
	
	if (strcmp(romanNumeral, "X") == 0)                 
		return 10;

	if (strcmp(romanNumeral, "L") == 0)                 
		return 50;

	if (strcmp(romanNumeral, "C") == 0)                 
		return 100;

	if (strcmp(romanNumeral, "D") == 0)                 
		return 500;

	if (strcmp(romanNumeral, "M") == 0)                 
		return 1000;

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

int addForArabic(const char* value1, const char* value2)
{
	// TODO: GUARD
	int a = getValue(value1);
	int b = getValue(value2);

	int outcome = a + b;
	
	return outcome;
}

int add(const char* value1, const char* value2, char* output)
{
	strcpy(output, "XXX");
	
	// TODO: status code
	return 1;
}
