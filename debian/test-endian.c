/* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2, or (at
 * your option) any later version.
 */

#include <stdio.h>

typedef long word_t;
typedef char byte_t;

union {
	word_t w;
	byte_t b[sizeof(word_t)];
} test;

int main()
{
	test.w = 0x44332211; // in order of significance

	if (test.b[0] == 0x11)
		puts("LO_HI_BYTE_ORDER");
	else if (test.b[(word_t) - 1] == 0x11)
		puts("HI_LO_BYTE_ORDER");
	else {
		puts("unkown");
		return 1;
	}

	return 0;
}

