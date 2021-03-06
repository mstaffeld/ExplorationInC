#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "Roman.h"
#include "Validation.h"
#include "Calculator.h"

int getArabicValue(const char* romanNumeral)
{
	int existingMatch = getValue(romanNumeral);
	if(existingMatch != -1)
		return existingMatch;

	int totalCharacters = strlen(romanNumeral);	
	int sumOfIndividualChars = 0;
	int previousValue = 0;
	char singleRoman[2] = {'\0', '\0'};
		
	for(int i = totalCharacters - 1; i >= 0; i--) 
	{
		int arabicValue = 0;
		singleRoman[0] = romanNumeral[i];
		arabicValue = getValue(singleRoman);		
		if(arabicValue < previousValue)
		{
			arabicValue = arabicValue * -1;
		}

		previousValue = arabicValue;		
		sumOfIndividualChars += arabicValue;	
	}	
	
	return sumOfIndividualChars;
}

static const char *romanValues[13] = { "I", "IV", "V", "IX", "X", "IL", "L", "XC", "C", "CD", "D", "CM", "M" };
static const int arabicValues[13] =  {   1,    4,   5,    9,  10,   40,  50,   90, 100,  400,  500, 900, 1000 };

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

int addForArabic(const char* value1, const char* value2)
{
	int a = getArabicValue(value1);
	int b = getArabicValue(value2);

	int outcome = a + b;
	
	return outcome;
}