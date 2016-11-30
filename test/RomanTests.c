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
	ck_assert_int_eq(getValue("V"), 5);
	ck_assert_int_eq(getValue("X"), 10);
	ck_assert_int_eq(getValue("L"), 50);
	ck_assert_int_eq(getValue("C"), 100);
	ck_assert_int_eq(getValue("D"), 500);
	ck_assert_int_eq(getValue("M"), 1000);
}
END_TEST

START_TEST(test_roman_numeral_throws_if_invalid)
{
	ck_assert_int_eq(getValue("R"), -1);
}
END_TEST

START_TEST(test_roman_numeral_add_basic_returns)
{
	ck_assert_int_eq(add("I","I"), 2);
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

	suite_add_tcase(suite, romanCase);

	return suite;
}
