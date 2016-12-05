#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "Validation.h"
#include "Roman.h"

int isRoman(const char* characters)
{
	if(containsMoreThanAllowedIXC(characters))
		return 0;

	if(containsMoreThanAllowedVLD(characters))
		return 0;

	char* validCharacters = "IVXLCDM";

	for(int i = 0; i < strlen(characters); i++)
	{
		if(strchr(validCharacters, characters[i]) == NULL)
		{
			return 0;
		}
	}

	int arabicValue = getArabicValue(characters);
	if(arabicValue > 3999)
		return 0;

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
