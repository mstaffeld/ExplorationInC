#include <stdio.h> 
#include <stdlib.h> 
#include <check.h> 

#include "ValidationTests.h" 
#include "../src/Validation.h"

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

	ck_assert_int_eq(isRoman("MMMCMXCIXI"), 0);
}
END_TEST

START_TEST(test_invalid_roman_numeral)
{
	ck_assert_int_eq(isRoman("O"), 0);
}
END_TEST

START_TEST(test_lowercase_invalid_roman_numeral)
{
	ck_assert_int_eq(isRoman("z"), 0);
        ck_assert_int_eq(isRoman("m"), 0);
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

Suite* validationSuite(void)
{
	Suite* suite = suite_create("Validation Tests");
	TCase* romanCase = tcase_create("Validation Test Case");
	tcase_add_test(romanCase, test_valid_roman_numeral);
	tcase_add_test(romanCase, test_invalid_roman_numeral);
	tcase_add_test(romanCase, test_invalid_roman_numerals);
	tcase_add_test(romanCase, test_valid_roman_numerals);
	tcase_add_test(romanCase, test_lowercase_invalid_roman_numeral);
	tcase_add_test(romanCase, test_lowercase_invalid_roman_numeral);
	tcase_add_test(romanCase, test_max_allowed);
	tcase_add_test(romanCase, test_max_allowed_vld);

	suite_add_tcase(suite, romanCase);

	return suite;
}
