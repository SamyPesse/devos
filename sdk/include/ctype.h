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

#ifndef _CTYPE_H_
#define _CTYPE_H_

int isupper( int c );
int islower( int c );
int isalpha( int c );
int isdigit( int c );
int isxdigit( int c );
int isalnum( int c );
int isblank( int c );
int isspace( int c );
int isprint( int c );
int iscntrl( int c );
int isgraph( int c );
int ispunct( int c );
int isascii( int c );

int tolower( int c );
int toupper( int c );

typedef struct {
	long quot;   
	long rem;  
}ldiv_t;

typedef struct {
	int quot;
	int rem;   
}div_t;

div_t div ( int numerator, int denominator );
ldiv_t ldiv ( long numerator, long denominator );




#endif // _CTYPE_H_
