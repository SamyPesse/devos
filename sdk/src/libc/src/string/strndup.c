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
 

#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

char* strndup( const char* s, size_t n ) {
    char* s2;
    size_t len;

    len = strlen( s );
    len = MIN( len, n );

    s2 = ( char* )malloc( len + 1 );

    if ( s2 == NULL ) {
        return NULL;
    }

    memcpy( s2, s, len );
    s2[ len ] = '\0';

    return s2;
}
