/*
    Roth programming language
    Copyright (C) 2015 Richard Palethorpe

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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

