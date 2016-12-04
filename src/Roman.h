#ifndef ROMAN_H
#define ROMAN_H

int convertToRoman(int arabic, char* output);
int getArabicValue(const char* romanNumeral);
int getValue(const char* romanNumeral);
int getRomanValue(const int arabicValue, char* romanValue);
int addForArabic(const char* value1, const char* value2);

#endif
