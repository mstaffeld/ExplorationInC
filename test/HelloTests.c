#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "HelloTests.h"
#include "../src/Hello.h"

START_TEST(hello_Returns_0)
{
	ck_assert_int_eq(returnZero(), 0);	
}
END_TEST

Suite* helloSuite(void)
{
	Suite* testSuite = suite_create("Hello Tests Suite");
	TCase* testCase = tcase_create("Plumbing works");
	tcase_add_test(testCase, hello_Returns_0);
	suite_add_tcase(testSuite, testCase);

	return testSuite;
}
