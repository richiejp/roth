
struct roth_lexer_ops {
	void (*log)(char *restrict);
};

int roth_lexer_init(struct roth_lexer_ops ops);
