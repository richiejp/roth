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

#include <string.h>
#include "util.h"
#include "lexer.h"

//#define STATE_STACK_SIZE 1

//State machine data
struct smd {
	//Current state
	int cs;

	//State stack
	//int stack[STATE_STACK_SIZE];

	//Top of stack
	//int top;

	//Most receant match
	//int act;

	//I don't know yet
	//char *ts;
	//char *te;
};
static struct smd smd;

%%{
machine lexer;

access smd.;

main := ['(', ')']*;

write data;
}%%

enum roth_lexer_error roth_lexer_init(struct roth_lexer_ops ops)
{
	%%{

	write init;

	}%%

	return RLE_NONE;
}

enum roth_lexer_error roth_lexer_go(char *data, char *dataend)
{
	char *p = data;
	char *pe = dataend;

	%%{
	
	write exec;

	}%%

	if(smd.cs < %%{ write first_final; }%% ) {
		return RLE_FATAL;
	}
	return RLE_NONE;
}

