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

#ifndef _STRING_H_
#define _STRING_H_

#define __need_size_t
#define __need_NULL
#include <stddef.h>

void* memset( void* s, int c, size_t n );
void* memcpy( void* d, const void* s, size_t n );
int memcmp( const void* p1, const void* p2, size_t c );
void* memmove( void* dest, const void* src, size_t n );
void* memchr( const void* s, int c, size_t n );

size_t strlen( const char* s );
size_t strnlen( const char* s, size_t count );
char* strchr( const char* s, int c );
char* strrchr( const char* s, int c );
char* strstr( const char* s1, const char* s2 );
int strcmp( const char* s1, const char* s2 );
int strncmp( const char* s1, const char* s2, size_t c );
int strcasecmp( const char* s1, const char* s2 );
int strncasecmp( const char* s1, const char* s2, size_t c );
char* strcpy( char* d, const char* s );
char* strncpy( char* d, const char* s, size_t c );
char* strcat( char* d, const char* s );
char* strncat( char* d, const char* s, size_t c );
char* strpbrk( const char* s, const char* accept );
size_t strspn( const char* s, const char* accept );
size_t strcspn( const char* s, const char* reject );
char* strtok_r( char* s, const char* delim, char** ptrptr );
char* strtok( char* s, const char* delim );

char* strdup( const char* s );
char* strndup( const char* s, size_t n);

char* strerror( int errnum );
char* strsignal( int signum );

#endif /* _STRING_H_ */
