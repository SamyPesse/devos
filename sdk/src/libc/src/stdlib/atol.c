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

long atol( const char* s ) {
    long v = 0;
    int sign = 0;

    while ( ( *s == ' ' ) || ( ( unsigned int )( *s - 9 ) < 5u ) ) {
        ++s;
    }

    switch ( *s ) {
        case '-' : sign = -1;
        case '+' : ++s;
    }

    while ( ( unsigned int )( *s - '0' ) < 10u ) {
        v = v * 10 + *s - '0';
        ++s;
    }

    return sign ? -v : v;
}
