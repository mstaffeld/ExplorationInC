#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "Roman.h"

void reverseArray(char arr[], int start, int end) 
{    
	char temp;     

	while (start < end)    
	{
		temp = arr[start];         
		arr[start] = arr[end];         
		arr[end] = temp;         
		start++;         
		end--;     
	} 
}

int getArabicValue(char* romanNumeral)
{
	printf("Roman Numeral: %s\n", romanNumeral); 	

	int totalCharacters = strlen(romanNumeral);
	reverseArray(romanNumeral, 0, totalCharacters - 1);

	printf("Reversed Numeral: %s\n", romanNumeral);
	
	int sumOfIndividualChars = 0;
	int previousValue = 0;
	
	for(int i = 0; i < totalCharacters; i++) 
	{
		int arabicValue = getValue(romanNumeral[i]);

		// if less than previous, convert to a negative 
		// if the same as previous, convert to a negative 
		if(arabicValue < previousValue)
		{
			// invert
			arabicValue = arabicValue * -1;
		}

		previousValue = arabicValue;		
		
		sumOfIndividualChars += arabicValue;
		
		printf("sum: %d\n", sumOfIndividualChars);	
	}	
	
	return sumOfIndividualChars;
}

int getValue(const char romanNumeral)
{
	int out = -1;
	switch(romanNumeral)
	{
		case 'I':
			out = 1;
			break;
		case 'V':
			out = 5;
			break;
		case 'X':
			out = 10;
			break;
		case 'L':
			out = 50;
			break;
		case 'C':
			out = 100;
			break;
		case 'D':
			out = 500;
			break;
		case 'M':	
			out = 1000;
			break;
	}

	return out;	
}

int convertToRoman(int arabic, char* output)
{
	

	return -1;
}

int getRomanValue(const int arabicValue, char* romanValue)
{
	switch(arabicValue)
	{
		case 1:
			strcat(romanValue, "I");
			return 1;
			break;
		case 5: 
			strcat(romanValue, "V");
			return 1;
			break;
		case 10:	
			strcat(romanValue, "X");
			return 1;	
			break;
		case 50:
			strcat(romanValue, "L");
			return 1;
			break;
		case 100:
			strcat(romanValue, "C");
			return 1;
			break;
		case 500:
			strcat(romanValue, "D");
			return 1;
			break;
		case 1000:
			strcat(romanValue, "M");
			return 1;
			break;
	}

	return -1;
}

int isRoman(const char* characters)
{
	if(containsMoreThanAllowedIXC(characters))
		return 0;

	if(containsMoreThanAllowedVLD(characters))
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

int addForArabic(const char value1, const char value2)
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
