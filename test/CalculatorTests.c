#include <stdio.h> 
#include <stdlib.h> 
#include <check.h> 

#include "CalculatorTests.h" 
#include "../src/Calculator.h"


static void assertAdd(char* value1, char* value2, char* expected, int expectedStatusCode)
{
	char output[3] = {'\0'};
	int status = add(value1, value2, output);

	ck_assert_int_eq(status, expectedStatusCode);
	ck_assert_str_eq(output, expected);
}

static void assertSubtract(char* value1, char* value2, char* expected, int expectedStatusCode)
{
	char output[3] = {'\0'};
	int status = subtract(value1, value2, output);
	
	ck_assert_int_eq(status, expectedStatusCode);
	ck_assert_str_eq(output, expected);
}

START_TEST(test_valid_inputs)
{
	assertAdd("X", "V", "XV", 1);
	assertAdd("X", "VI", "XVI", 1);
	assertAdd("X", "L", "LX", 1);
	assertAdd("X", "C", "CX", 1);	
	
	assertSubtract("X", "V", "V", 1);
	assertSubtract("x", "v", "", -1);	
	assertSubtract("X", "X", "", -1);
	
	//assertSubtract("L", "X", "XL", 1);
	//assertSubtract("x", "v", "v", 1);


}
END_TEST

START_TEST(test_validation_rejects)
{
	assertAdd("IIII", "D", "", -1);
	assertAdd("XXXX", "CCCCC", "", -1);
	assertAdd("VVV", "I", "", -1);
	assertAdd("VX", "DD", "", -1);
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
	tcase_add_test(romanCase, test_valid_inputs);
	tcase_add_test(romanCase, test_validation_rejects);

	suite_add_tcase(suite, romanCase);

	return suite;
}
