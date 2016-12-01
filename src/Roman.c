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

int getRomanValue(const int arabicValue, char* romanValue)
{
	if(arabicValue == 1)
		strcpy(romanValue, "I");

	if(arabicValue == 5)
		strcpy(romanValue, "V");

	if(arabicValue == 10)	
		strcpy(romanValue, "X");

	if(arabicValue == 50)
		strcpy(romanValue, "L");

	if(arabicValue == 100)
		strcpy(romanValue, "C");

	if(arabicValue == 500)
		strcpy(romanValue, "D");
	
	if(arabicValue == 1000)
		strcpy(romanValue, "M");

	return 1;
}

int isRoman(const char* characters)
{
	if(containsMoreThanAllowedIXC(characters))
		return 0;

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

int containsMoreThanAllowedIXC(const char* characters)
{
	int iCount = 0;
	int xCount = 0; 
	int cCount = 0;

        for (int i = 0; i < strlen(characters); i++)
	{
		if(toupper(characters[i]) == 'I')
			iCount++;
	
		if(toupper(characters[i]) == 'X')
			xCount++;
	
		if(toupper(characters[i]) == 'C')
			cCount++;
	}                

	if(iCount > 3 || xCount > 3 || cCount > 3)
		return 1;

	return 0;
}

int containsMoreThanAllowedVLD(const char* characters)
{
	int vCount = 0;
	int lCount = 0;
	int dCount = 0;

	for (int i = 0; i < strlen(characters); i++) 
	{         
		if(toupper(characters[i]) == 'V')                 
			vCount++;          

		if(toupper(characters[i]) == 'L')
	                 lCount++;          

		if(toupper(characters[i]) == 'D')                 
			dCount++;   
	}
	
	if(vCount > 1 || lCount > 1 || dCount > 1)
		return 1;  

	return 0;
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
