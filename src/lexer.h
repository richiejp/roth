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

enum roth_lexer_error {
	RLE_NONE = 0,
	RLE_FATAL = 1
};

//Callbacks to other modules
struct roth_lexer_ops {
	enum roth_lexer_error (*todo)(char *restrict);
};

enum roth_lexer_error roth_lexer_init(struct roth_lexer_ops ops);
enum roth_lexer_error roth_lexer_go(char *data, char* dataend);
