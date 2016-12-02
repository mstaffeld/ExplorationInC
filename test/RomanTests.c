#include <stdio.h> 
#include <stdlib.h> 
#include <check.h> 
#include "RomanTests.h" 
#include "../src/Roman.h"

START_TEST(test_valid_roman_numeral)
{
	ck_assert_msg(isRoman("I"), "Value is not a roman numeral!");
	ck_assert_msg(isRoman("V"), "Value is not a roman numeral!");
	ck_assert_msg(isRoman("X"), "Value is not a roman numeral!");
	ck_assert_msg(isRoman("L"), "Value is not a roman numeral!");
	ck_assert_msg(isRoman("C"), "Value is not a roman numeral!");
	ck_assert_msg(isRoman("D"), "Value is not a roman numeral!");
	ck_assert_msg(isRoman("M"), "Value is not a roman numeral!");
}
END_TEST

START_TEST(test_valid_roman_numerals)
{
	ck_assert_int_eq(isRoman("IVX"), 1);
}
END_TEST

START_TEST(test_invalid_roman_numerals)
{
	ck_assert_int_eq(isRoman("IP"), 0);
	ck_assert_int_eq(isRoman("IIII"), 0);
	ck_assert_int_eq(isRoman("XXXX"), 0);
	ck_assert_int_eq(isRoman("CCCC"), 0);	

	ck_assert_int_eq(isRoman("VV"), 0);
	ck_assert_int_eq(isRoman("LL"), 0);
	ck_assert_int_eq(isRoman("DD"), 0);
}
END_TEST

START_TEST(test_invalid_roman_numeral)
{
	ck_assert_int_eq(isRoman("O"), 0);
}
END_TEST

START_TEST(test_lowercase_valid_roman_numeral)
{
	 ck_assert_int_eq(isRoman("m"), 1);
}
END_TEST

START_TEST(test_lowercase_invalid_roman_numeral)
{
	ck_assert_int_eq(isRoman("z"), 0);
}
END_TEST

START_TEST(test_roman_numeral_has_value)
{
	ck_assert_int_eq(getValue("I"), 1);
	ck_assert_int_eq(getValue("IV"), 4);
	ck_assert_int_eq(getValue("V"), 5);
	ck_assert_int_eq(getValue("IX"), 9);
	ck_assert_int_eq(getValue("X"), 10);
	ck_assert_int_eq(getValue("IL"), 40);
	ck_assert_int_eq(getValue("L"), 50);
	ck_assert_int_eq(getValue("XC"), 90);
	ck_assert_int_eq(getValue("C"), 100);
	ck_assert_int_eq(getValue("CD"), 400);
	ck_assert_int_eq(getValue("D"), 500);
	ck_assert_int_eq(getValue("CM"), 900);
	ck_assert_int_eq(getValue("M"), 1000);
}
END_TEST

START_TEST(test_roman_numeral_calculates)
{
	//TODO: clean this up
	char numeral[]= "IV";
	ck_assert_int_eq(getArabicValue(numeral), 4);

	char numeral1[] = "IX";
	ck_assert_int_eq(getArabicValue(numeral1), 9);

	char numeral2[] = "VD";
	ck_assert_int_eq(getArabicValue(numeral2), 495);

	char numeral3[] = "XXII";
	ck_assert_int_eq(getArabicValue(numeral3), 22);
	
	char numeral4[] = "DCLXVII";
	ck_assert_int_eq(getArabicValue(numeral4), 667);

	char numeral5[] = "MMMCMXCIX";
	ck_assert_int_eq(getArabicValue(numeral5), 3999);

	char numeral6[] = "MMMCMVC";
	ck_assert_int_eq(getArabicValue(numeral6), 3995);
}
END_TEST

START_TEST(test_roman_numeral_throws_if_invalid)
{
	ck_assert_int_eq(getValue("R"), -1);
}
END_TEST

START_TEST(test_roman_numeral_add_basic_returns)
{
	ck_assert_int_eq(addForArabic("I", "I"), 2);
	ck_assert_int_eq(addForArabic("I", "V"), 6);
	ck_assert_int_eq(addForArabic("V", "V"), 10);
	ck_assert_int_eq(addForArabic("D", "C"), 600);
}
END_TEST

START_TEST(test_add_returns_roman)
{
	// TODO: make a helper method
	char output[13] = "";
	int status = add("X", "V", output);
	ck_assert_int_eq(status, 1);
	ck_assert_str_eq(output, "XV");
	
	output[0] = '\0';
	status = add("XX", "V", output);
	ck_assert_int_eq(status, 1);
	ck_assert_str_eq(output, "XXV");

	output[0] = '\0';
	status = add("MMC", "VII", output);
	ck_assert_int_eq(status, 1);
	ck_assert_str_eq(output, "MMCVII");
	
	output[0] = '\0';
	status = add("MMC", "VIIIII", output);
	ck_assert_int_eq(status, 1);
	ck_assert_str_eq(output, "MMCX");

}
END_TEST

START_TEST(test_subtract_returns_roman)
{
	char output[13] = "";
	int status = subtract("X", "C", output);
	ck_assert_int_eq(status, -1);
	
	output[0] = '\0';
	status = subtract("X", "V", output);
	ck_assert_int_eq(status, 1);
	ck_assert_str_eq(output, "V");
}
END_TEST

START_TEST(test_get_roman_returns_roman)
{
	char output[3] = {'\0'};
	int status = getRomanValue(1, output);
        ck_assert_int_eq(status, 1);
        ck_assert_str_eq(output, "I");

	output[0] = '\0';	
	getRomanValue(5, output);
	ck_assert_str_eq(output, "V");

	output[0] = '\0';	
	getRomanValue(10, output);
        ck_assert_str_eq(output, "X");

	output[0] = '\0';	
	getRomanValue(50, output);
	ck_assert_str_eq(output, "L");

	output[0] = '\0';	
	getRomanValue(100, output);
	ck_assert_str_eq(output, "C");
	
	output[0] = '\0';	
	getRomanValue(500, output);
	ck_assert_str_eq(output, "D");

	output[0] = '\0';	
	getRomanValue(1000, output);
	ck_assert_str_eq(output, "M");
	output[0] = '\0';
}
END_TEST

START_TEST(test_arabic_converts_to_roman)
{
	char output[3] = {'\0'};         
	int status = convertToRoman(5, output);         
	ck_assert_int_eq(status, 1);         
	ck_assert_str_eq(output, "V");
	output[0] = '\0';

	char output2[3] = {'\0'};
	convertToRoman(6, output2);
	ck_assert_int_eq(status, 1);
	ck_assert_str_eq(output2, "VI");
	output2[0] = '\0';	
}
END_TEST

START_TEST(test_max_allowed)
{
	ck_assert_int_eq(containsMoreThanAllowedIXC("IIII"), 1);
	ck_assert_int_eq(containsMoreThanAllowedIXC("XXXX"), 1);
	ck_assert_int_eq(containsMoreThanAllowedIXC("CCCC"), 1);
	ck_assert_int_eq(containsMoreThanAllowedIXC("ZXCBNEEW"), 0);
	ck_assert_int_eq(containsMoreThanAllowedIXC("MIMIMIMI"), 1);
	ck_assert_int_eq(containsMoreThanAllowedIXC("XeXiXbiAX"), 1);
	
	ck_assert_int_eq(containsMoreThanAllowedVLD("VV"), 1);
	ck_assert_int_eq(containsMoreThanAllowedVLD("LL"), 1);
	ck_assert_int_eq(containsMoreThanAllowedVLD("DD"), 1);
	ck_assert_int_eq(containsMoreThanAllowedVLD("VLDVLDVLD"), 1);
}
END_TEST

START_TEST(test_max_allowed_vld)
{
	ck_assert_int_eq(containsMoreThanAllowedVLD("VV"), 1); 
        ck_assert_int_eq(containsMoreThanAllowedVLD("LL"), 1);
        ck_assert_int_eq(containsMoreThanAllowedVLD("DD"), 1);
        ck_assert_int_eq(containsMoreThanAllowedVLD("VLDVLDVLD"), 1);

	ck_assert_int_eq(containsMoreThanAllowedVLD("VLDAEJIJOERK"), 0);
}
END_TEST

Suite* romanSuite(void)
{
	Suite* suite = suite_create("Roman Tests");
	TCase* romanCase = tcase_create("Roman Tests");
	tcase_add_test(romanCase, test_valid_roman_numeral);
	tcase_add_test(romanCase, test_valid_roman_numerals);
	tcase_add_test(romanCase, test_invalid_roman_numeral);
	tcase_add_test(romanCase, test_invalid_roman_numerals);
	tcase_add_test(romanCase, test_lowercase_valid_roman_numeral);
	tcase_add_test(romanCase, test_lowercase_invalid_roman_numeral);
	tcase_add_test(romanCase, test_roman_numeral_has_value);
	tcase_add_test(romanCase, test_roman_numeral_throws_if_invalid);	
	tcase_add_test(romanCase, test_roman_numeral_add_basic_returns);
	tcase_add_test(romanCase, test_add_returns_roman);
	tcase_add_test(romanCase, test_subtract_returns_roman);
	tcase_add_test(romanCase, test_get_roman_returns_roman);
	tcase_add_test(romanCase, test_max_allowed);
	tcase_add_test(romanCase, test_max_allowed_vld);
	tcase_add_test(romanCase, test_roman_numeral_calculates);
	tcase_add_test(romanCase, test_arabic_converts_to_roman);	
	suite_add_tcase(suite, romanCase);

	return suite;
}
