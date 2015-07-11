#define _STDC_WANT_LIB_EXT1_ 1

#include <stdlib.h>
#include <stdio.h>

#ifdef _STDC_LIB_EXT1_
#define roth_printf printf_s
#else
#define roth_printf printf
#endif

#define ROTH_LOG(msg, ...)				\
	do{						\
		roth_printf("[%s] ", __FILE__);		\
		roth_printf(msg, ##__VA_ARGS__);	\
		roth_printf("\n");			\
	}while(0)

#define ROTH_DEBUG(msg, ...)				\
	do{						\
		roth_printf("[%s] ", __LINE__);		\
		roth_printf(msg, ##__VA_ARGS__);	\
		roth_printf("\n");			\
	}while(0)
