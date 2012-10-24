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
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <inttypes.h>

unsigned long long int strtoull( const char* ptr, char** endptr, int base ) {
    int neg = 0, overflow = 0;
    long long int v = 0;
    const char* orig;
    const char* nptr = ptr;

    while ( isspace( *nptr ) ) {
        ++nptr;
    }

    if ( *nptr == '-' ) {
        neg=1;
        nptr++;
    } else if ( *nptr == '+' ) {
        ++nptr;
    }

    orig = nptr;

    if ( ( base == 16 ) && ( nptr[ 0 ] == '0' ) ) {
        goto skip0x;
    }

    if ( base ) {
        register unsigned int b = base - 2;

        if ( b > 34 ) {
            errno = EINVAL;
            return 0;
        }
    } else {
        if ( *nptr == '0' ) {
            base = 8;

skip0x:
            if ( ( ( *( nptr + 1 ) == 'x' ) || ( *( nptr + 1 ) == 'X' ) ) && isxdigit( nptr[ 2 ] ) ) {
                nptr += 2;
                base = 16;
            }
        } else {
            base = 10;
        }
    }

    while ( *nptr ) {
        register unsigned char c = *nptr;

        c = ( c >= 'a' ? c - 'a' + 10 : c >= 'A' ? c - 'A' + 10 : c <= '9' ? c - '0' : 0xFF );

        if ( c >= base ) {
            break;	/* out of base */
        }

        {
            register unsigned long x = ( v & 0xFF ) * base + c;
            register unsigned long long w = ( v >> 8 ) * base + ( x >> 8 );

            if ( w > ( ULLONG_MAX >> 8 ) ) {
                overflow = 1;
            }

            v = ( w << 8 ) + ( x & 0xFF );
        }

        ++nptr;
    }

    if ( nptr == orig ) {		/* no conversion done */
        nptr = ptr;
        errno = EINVAL;
        v = 0;
    }

    if ( endptr != NULL ) {
        *endptr = (char *)nptr;
    }

    if ( overflow ) {
        errno = ERANGE;
        return ULLONG_MAX;
    }

    return ( neg ? -v : v );
}

uintmax_t strtoumax( const char* nptr, char** endptr, int base ) __attribute__(( alias( "strtoull" ) ));
