#include <stdio.h> 
#include <stdlib.h> 
#include <check.h> 
#include "CalculatorTests.h" 
#include "../src/Calculator.h"


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

	output[0] = '\0';
	status = subtract("CCC", "IL", output);
	ck_assert_int_eq(status, 1);
	ck_assert_str_eq(output, "CCLX");
}
END_TEST

Suite* calculatorSuite(void)
{
	Suite* suite = suite_create("Calculator Tests");
	TCase* romanCase = tcase_create("Calculator Tests Case");

	tcase_add_test(romanCase, test_add_returns_roman);
	tcase_add_test(romanCase, test_subtract_returns_roman);

	suite_add_tcase(suite, romanCase);

	return suite;
}
