#include <stdlib.h>
#include <check.h>

#include "RomanTests.h"
#include "ValidationTests.h"
#include "CalculatorTests.h"

int main()
{
	Suite* suite1 = romanSuite();
	SRunner *suiteRunner = srunner_create(suite1);

	Suite* suite2 = validationSuite();
	srunner_add_suite(suiteRunner, suite2);

	Suite* suite3 = calculatorSuite();
	srunner_add_suite(suiteRunner, suite3);

	srunner_run_all(suiteRunner, CK_NORMAL);

	int failures;
	failures = srunner_ntests_failed(suiteRunner);
	
	srunner_free(suiteRunner);
	
	if(failures == 0)
		return EXIT_SUCCESS;
	
	return EXIT_FAILURE;
}
