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
	int existingMatch = getValue(romanNumeral);
	if(existingMatch != -1)
		return existingMatch;

	//printf("Roman Numeral: %s\n", romanNumeral); 	

	int totalCharacters = strlen(romanNumeral);
	reverseArray(romanNumeral, 0, totalCharacters - 1);

	//printf("Reversed Numeral: %s\n", romanNumeral);
	
	int sumOfIndividualChars = 0;
	int previousValue = 0;
	char singleRoman[2] = {'\0', '\0'};
		
	for(int i = 0; i < totalCharacters; i++) 
	{
		int arabicValue = 0;
		singleRoman[0] = romanNumeral[i];
		//printf("romanNumeral[i] = %d\n", romanNumeral[i]);
		//printf("singleroman[0] = %c\n", singleRoman[0]);

		arabicValue = getValue(singleRoman);		

		// if less than previous, convert to a negative 
		// if the same as previous, convert to a negative 
		//printf("arabicValue = %d\n", arabicValue);
		if(arabicValue < previousValue)
		{
			// invert
			arabicValue = arabicValue * -1;
		}

		previousValue = arabicValue;		
		
		sumOfIndividualChars += arabicValue;
		
		//printf("sum: %d\n", sumOfIndividualChars);	
	}	
	
	return sumOfIndividualChars;
}

static const char *romanValues[13] = { "I", "IV", "V", "IX", "X", "IL", "L", "XC", "C", "CD", "D", "CM", "M" };
static const int arabicValues[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

int getValue(const char* romanNumeral)
{
	int romanSize = sizeof(romanValues)/sizeof(romanValues[0]); 
	int i; 

	for(i = 0; i < romanSize; ++i) 
	{     
		if (strcmp(romanValues[i], romanNumeral) == 0) 
		{         
			return arabicValues[i];
		} 
	}
	
	return -1;
}

int getRomanValue(const int arabicValue, char* romanValue)
{
	int arabicSize = sizeof(arabicValues)/sizeof(arabicValues[0]);         
	int i;          
	
	for(i = 0; i < arabicSize; ++i)        
	{
		if(arabicValues[i] == arabicValue)
		{
			strcpy(romanValue, romanValues[i]);
			return 1;
		}
	}          

	return -1;
}

static int calculateRoman(int arabicValue, char* romanValue)
{
	int i;
	for(i = 12; i >= 0; i--)
	{
		while(arabicValue >= arabicValues[i])
		{             
			arabicValue -= arabicValues[i];  
			strcat(romanValue, romanValues[i]); 
		}
	}

	return -1;
}

int convertToRoman(int arabicValue, char* romanValue)
{
	char output[3] = {'\0'};
	int status = -1;
	
	status = getRomanValue(arabicValue, output);

	if(status == 1) //found, simple
	{
		strcpy(romanValue, output);
		return 1;
	}

	return calculateRoman(arabicValue, romanValue);
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
	printf("output: %s\n", output);

	// TODO: GUARD
	int arabicSum = addForArabic(value1, value2);
	printf("arabicsum: %d\n", arabicSum);

	convertToRoman(arabicSum, output);
	printf("out: %s\n", output);	
	
	// TODO: status code
	return 1;
}
