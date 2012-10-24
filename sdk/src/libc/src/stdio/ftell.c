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
#include <unistd.h>
#include <errno.h>
#include <limits.h>

off_t ftello( FILE* stream ) {
    off_t l;

    if ( stream->flags & ( __FILE_EOF | __FILE_ERROR ) ) {
        return -1;
    }

    l = lseek( stream->fd, 0, SEEK_CUR );

    if ( l == ( off_t )-1 ) {
        return -1;
    }

    if ( stream->flags & __FILE_BUFINPUT ) {
        return l - ( stream->buffer_data_size - stream->buffer_pos ) - stream->has_ungotten;
    } else {
        return l + stream->buffer_pos;
    }
}

long ftell( FILE* stream ) {
    off_t l;

    l = ftello( stream );

    if ( l > LONG_MAX ) {
        errno = EOVERFLOW;
        return -1;
    }

    return ( long )l;
}
