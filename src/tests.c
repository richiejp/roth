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

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"
#include "lexer.h"

#define TESTCOUNT 4

#define TEST(n)	static bool _##n(char **name);	\
static bool n(char **name)			\
{						\
	*name = #n;				\
	return _##n;				\
}						\
static bool _##n()

//Array of test function pointers: bool test(char *name)
static bool (*tests[TESTCOUNT])(char **);

static bool testme(char **name)
{
	*name = "testme";
	return true;
}

TEST(test_macro_test)
{
	return true;
}

TEST(init_lexer)
{
	struct roth_lexer_ops lops;
	return roth_lexer_init(lops);
}

TEST(lex_empty_list)
{
	char *code = "()";
	struct roth_lexer_ops lops;
	roth_lexer_init(lops);
	return roth_lexer_go(code, strchr(code, 0));
}

int main(){
	int failed = 0;
	char *name = "unnamed!";

	roth_printf("\n	--==[ Running Roth tests ]==--\n\n");

	tests[0] = testme;
	tests[1] = test_macro_test;
	tests[2] = init_lexer;
	tests[3] = lex_empty_list;

	for(int i = 0; i < TESTCOUNT; i++) {
		if((*tests[i])(&name)) {
			roth_printf("[Test %d]Passed %s\n", i+1, name);
		} else {
			roth_printf("\n[Test %d]Failed %s!!!!!!!\n", i+1, name);
		}
	}

	roth_printf("\n	-{ %d tests failed out of %d }-\n", failed, TESTCOUNT);

	return 0;
}

