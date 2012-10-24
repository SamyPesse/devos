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

extern char** environ;

char* getenv( const char* name ) {
	return NULL;
	
    int i;
    size_t length;
    size_t name_length;

    name_length = strlen( name );

    for ( i = 0; environ[ i ] != NULL; i++ ) {
        length = strlen( environ[ i ] );

        if ( length < ( name_length + 1 ) ) {
            continue;
        }

        if ( ( strncmp( environ[ i ], name, name_length ) == 0 ) &&
             ( environ[ i ][ name_length ] == '=' ) ) {
            return &environ[ i ][ name_length + 1 ];
        }
    }

    return NULL;
}
