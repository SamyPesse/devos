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
 

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#ifndef O_NOFOLLOW
#define O_NOFOLLOW 0
#endif

int mkstemp( char* template ) {
    int i;
    char* tmp;
    int result;
    unsigned int rnd;

    tmp = template + strlen( template ) - 6;

    if ( tmp < template ) {
        errno = EINVAL;
        return -1;
    }

    for ( i = 0; i < 6; i++ ) {
        if ( tmp[ i ] != 'X' ) {
            errno = EINVAL;
            return -1;
        }
    }

    for ( ;; ) {
        for ( i = 0; i < 6; i++ ) {
            int hexdigit;

            rnd = random();
            hexdigit = ( rnd >> ( i * 5 ) ) & 0x1F;
            tmp[ i ] = hexdigit > 9 ? ( hexdigit + 'a' - 10 ) : ( hexdigit + '0' );
        }

        result = open( template, O_CREAT | O_RDWR | O_EXCL | O_NOFOLLOW, 0600 );

        if ( ( result >= 0 ) ||
             ( errno != EEXIST ) ) {
            break;
        }
    }

    return result;
}
