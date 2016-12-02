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
		// HACK
		//int arabicValue = getValue(singleRoman[0] = romanNumeral[i]);
		int arabicValue = 0;
		
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

int convertToRoman(int arabicValue, char* romanValue)
{
	// start with 6, VI
	char output[3] = {'\0'};
	int status = -1;
	
	status = getRomanValue(arabicValue, output);

	if(status == 1) //found, simple
	{
		strcpy(romanValue, output);
		return 1;
	}
	

	return -1;
}

int getRomanValue(const int arabicValue, char* romanValue)
{
	switch(arabicValue)
	{
		case 1:
			strcpy(romanValue, "I");
			return 1;
			break;
		case 5: 
			strcpy(romanValue, "V");
			return 1;
			break;
		case 10:	
			strcpy(romanValue, "X");
			return 1;	
			break;
		case 50:
			strcpy(romanValue, "L");
			return 1;
			break;
		case 100:
			strcpy(romanValue, "C");
			return 1;
			break;
		case 500:
			strcpy(romanValue, "D");
			return 1;
			break;
		case 1000:
			strcpy(romanValue, "M");
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
