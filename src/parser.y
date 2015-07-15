%token_type {int}

%include {
#include "assert.h"
#include "util.h"
#include "parser.h"
}

%syntax_error {
	ROTH_LOG("Syntax Error, good luck working out why!");
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
