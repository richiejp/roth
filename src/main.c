#include "lexer.h"

int main(int argc, char **argv)
{
	struct roth_lexer_ops lops = { 
		log = printf_s
	};

	roth_lexer_init(lops);

	return 0;
}
