#define _STDC_WANT_LIB_EXT1_ 1

#include <stdio.h>
#include <stdbool.h>
#include "lexer.h"

#ifdef _STDC_LIB_EXT1_
#define PRINT printf_s
#else
#define PRINT printf
#endif

#define TESTCOUNT 1

//Array of test function pointers: bool test(char *name)
static bool (*tests[TESTCOUNT])(char **);

static bool testme(char **name) {
	*name = "testme";
	return true;
}

int main(){
	int failed = 0;
	char *name = "unnamed!";

	tests[0] = testme;

	for(int i = 0; i < TESTCOUNT; i++) {
		if((*tests[i])(&name)) {
			PRINT("[%d]Passed %s\n", i, name);
		} else {
			PRINT("[%d]Failed %s\n", i, name);
		}
	}

	PRINT("\n%d tests failed out of %d\n", failed, TESTCOUNT);
}

