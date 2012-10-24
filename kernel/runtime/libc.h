/**
 *	Koala Operating System
 *	Copyright (C) 2010 - 2011 Samy Pessé
 *	
 *	This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundatn 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
#ifndef LIBC_H
#define LIBC_H

#include <stdarg.h>

extern "C" {
	void 	itoa(char *buf, unsigned long int n, int base);
	
	void *	memset(char *dst,char src, int n);
	void *	memcpy(char *dst, char *src, int n);
	
	
	int 	strlen(char *s);
	int 	strcmp(const char *dst, char *src);
	int 	strcpy(char *dst,const char *src);
	void 	strcat(void *dest,const void *src);
	char *	strncpy(char *destString, const char *sourceString,int maxLength);
	int 	strncmp( const char* s1, const char* s2, int c );
}

#endif
