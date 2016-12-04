#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "Roman.h"
#include "Validation.h"

int add(const char* value1, const char* value2, char* output)
{
	// TODO: GUARD
	int arabicSum = addForArabic(value1, value2);
	//printf("arabicsum: %d\n", arabicSum);

	convertToRoman(arabicSum, output);
	//printf("out: %s\n", output);	
	
	// TODO: status code
	return 1;
}

int subtract(const char* value1, const char* value2, char* output)
{
	// TODO: GUARD
	int a = getArabicValue(value1);
	printf("a: %d\n", a);
	
	int b = getArabicValue(value2);
	printf("b: %d\n", b);	

	if(b > a)
		return -1;

	int arabicDifference = a - b;
	printf("arabicDifference: %d\n", arabicDifference);
	
	convertToRoman(arabicDifference, output);
	
	// TODO: status code		
	return 1;
}
