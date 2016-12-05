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
	assertAdd("X", "X", "XXV", 1);	
	assertAdd("MMC", "VII", "MMCVII", 1);
	
	assertSubtract("X", "V", "V", 1);
	assertSubtract("CCC", "IL", "CCLX", 1);
}
END_TEST

START_TEST(test_validation_rejects)
{
	assertAdd("IIII", "D", "", -1);
	assertAdd("XXXX", "CCCCC", "", -1);
	assertAdd("VVV", "I", "", -1);
	assertAdd("VX", "DD", "", -1);

	assertSubtract("x", "v", "", -1);	
	assertSubtract("X", "X", "", -1);
	assertSubtract("X", "C", "", -1);

}
END_TEST

Suite* calculatorSuite(void)
{
	Suite* suite = suite_create("Calculator Tests");
	TCase* romanCase = tcase_create("Calculator Tests Case");

	tcase_add_test(romanCase, test_valid_inputs);
	tcase_add_test(romanCase, test_validation_rejects);

	suite_add_tcase(suite, romanCase);

	return suite;
}
