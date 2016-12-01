#ifndef ROMAN_H
#define ROMAN_H

int getArabicValue(const char* romanNumeral);
int getValue(const char* romanNumeral);
int isRoman(const char* characters);
int add(const char* value1, const char* value2, char* output);
int addForArabic(const char* value1, const char* value2);
int getRomanValue(const int arabicValue, char* romanValue);
int containsMoreThanAllowedIXC(const char* characters);
int containsMoreThanAllowedVLD(const char* characters);

#endif
