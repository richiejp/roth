%token_type {int}

%include {
#include "assert.h"
#include "util.h"
#include "parser.h"
}

%name roth_parser_
%token_prefix ROTH_TOK_
//%token_type { int }

%syntax_error {
	ROTH_LOG("Syntax Error, good luck working out why!");
}

%parse_failure {
	ROTH_LOG("I can't deal with this mess.");
}

%stack_overflow {
	ROTH_LOG("STOP, STOP, too much, my stack is too small for that!");
}

program ::= sexp(A). { 
	ROTH_DEBUG("sexps = %d", A); 
}

sexp(A) ::= LP sexp(B) RP. { 
	ROTH_DEBUG("Populated sexp with %d", B); 
	A = 1 + B;
}

sexp(A) ::= LP RP. { 
	ROTH_DEBUG("Empty sexp"); 
	A = 1;
}
