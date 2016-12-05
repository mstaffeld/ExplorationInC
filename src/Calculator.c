#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "Roman.h"
#include "Validation.h"

int add(const char* value1, const char* value2, char* output)
{
	if(!isRoman(value1) || !isRoman(value2))
		return -1;
	
	int arabicSum = addForArabic(value1, value2);
	convertToRoman(arabicSum, output);
	
	return 1;
}

int subtract(const char* value1, const char* value2, char* output)
{
	if(!isRoman(value1) || !isRoman(value2))
		return -1;
	
	int a = getArabicValue(value1);	
	int b = getArabicValue(value2);

	if(b >= a)
		return -1;

	int arabicDifference = a - b;
	convertToRoman(arabicDifference, output);
	
	return 1;
}
