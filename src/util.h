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
#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wunused-macros"
#endif

//Request safe functions
#define _STDC_WANT_LIB_EXT1_ 1

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <stdlib.h>
#include <stdio.h>

//Use safe functions if we have them
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
		roth_printf("[%s:%s:%d] ",			\
			    __FILE__, __func__, __LINE__);		\
		roth_printf(msg, ##__VA_ARGS__);	\
		roth_printf("\n");			\
	}while(0)
