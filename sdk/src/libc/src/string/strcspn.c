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
 

#include <string.h>
#include <sys/types.h>

size_t strcspn( const char* s, const char* reject ) {
    size_t l = 0;
    int a = 1;
    int i;
    int al = strlen( reject );

    while ( ( a ) && ( *s ) ) {
        for ( i = 0; ( a ) && ( i < al ); i++ ) {
            if ( *s == reject[ i ] ) {
                a = 0;
            }
        }

        if ( a ) {
            l++;
        }

        s++;
    }

    return l;
}
