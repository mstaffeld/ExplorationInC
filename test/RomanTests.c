#include <stdio.h> 
#include <stdlib.h> 
#include <check.h> 
#include "RomanTests.h" 
#include "../src/Roman.h"

START_TEST(test_valid_roman_numeral)
{
	ck_assert_msg(isRoman("U"), "Value is not a roman numeral!");

}
END_TEST

Suite* romanSuite(void)
{
	Suite* suite = suite_create("Roman Tests");
	TCase* romanCase = tcase_create("Roman Tests");
	tcase_add_test(romanCase, test_valid_roman_numeral);
	suite_add_tcase(suite, romanCase);

	
	return suite;
}
