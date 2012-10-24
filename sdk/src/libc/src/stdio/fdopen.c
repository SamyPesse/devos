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
#include <errno.h>

int __parse_mode( const char* mode );
FILE* __init_file( int fd, int close_on_error, int mode );

FILE* fdopen( int fd, const char* mode ) {
    int flags;

    if ( fd < 0 ) {
        errno = -EINVAL;
        return NULL;
    }

    flags = __parse_mode( mode );

    return __init_file( fd, 0, flags );
}
