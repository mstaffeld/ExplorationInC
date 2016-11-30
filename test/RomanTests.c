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

START_TEST(test_invalid_roman_numeral)
{
	ck_assert_int_eq(isRoman("O"), 0);
}
END_TEST

Suite* romanSuite(void)
{
	Suite* suite = suite_create("Roman Tests");
	TCase* romanCase = tcase_create("Roman Tests");
	tcase_add_test(romanCase, test_valid_roman_numeral);
	tcase_add_test(romanCase, test_invalid_roman_numeral);
	suite_add_tcase(suite, romanCase);

	return suite;
}
