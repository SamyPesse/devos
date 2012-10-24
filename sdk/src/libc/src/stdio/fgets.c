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
 

#include <stdio.h>

char* fgets( char* s, int size, FILE* stream ) {
    char* orig = s;
    int l;

    for ( l = size; l > 1; ) {
        register int c = fgetc( stream );
		//printf("c:  %c \n");
        if ( c == EOF ) {
            break;
        }

        *s = c;
        ++s;
        --l;

        if ( c == '\n' ) {
            break;
        }
    }

    if ( ( l == size ) || ( ferror( stream ) ) ) {
        return 0;
    }

    *s = 0;

    return orig;
}
