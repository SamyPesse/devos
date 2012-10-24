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
 

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#if __WORDSIZE == 64
#define ABS_LONG_MIN 9223372036854775808UL
#else
#define ABS_LONG_MIN 2147483648UL
#endif

long int strtol( const char* nptr, char** endptr, int base ) {
    int neg = 0;
    unsigned long int v;
    const char* orig = nptr;

    while ( isspace( *nptr ) ) {
        nptr++;
    }

    if ( ( *nptr == '-' ) && ( isalnum( nptr[ 1 ] ) ) ) {
        neg = -1;
        ++nptr;
    }

    v = strtoul( nptr, endptr, base );

    if ( ( endptr ) && ( *endptr == nptr) ) {
        *endptr = ( char* )orig;
    }

    if ( v >= ABS_LONG_MIN ) {
        if ( ( v == ABS_LONG_MIN ) && ( neg ) ) {
            return v;
        }

        return ( neg ? LONG_MIN : LONG_MAX );
    }

    return ( neg ? -v : v );
}
