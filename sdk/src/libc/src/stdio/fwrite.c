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
#include <sys/types.h>

size_t fwrite( const void* ptr, size_t size, size_t nmemb, FILE* stream ) {
    ssize_t res;
    unsigned long len=size * nmemb;
    long i;

    if ( ( stream->flags & __FILE_CAN_WRITE ) == 0 ) {
        stream->flags |= __FILE_ERROR;
        return 0;
    }

    if ( ( nmemb == 0 ) ||
         ( ( len / nmemb ) != size ) ) {
        return 0;
    }

    if ( ( len > stream->buffer_size ) || ( stream->flags & __FILE_NOBUF ) ) {
        if ( fflush( stream ) ) {
            return 0;
        }

        res = write( stream->fd, ptr, len );
    } else {
        register const unsigned char* c = ptr;

        for ( i = len; i > 0; --i, ++c ) {
            if ( fputc( *c, stream ) ) {
                res = len - i;
                goto abort;
            }
        }

        res = len;
    }

    if ( res < 0 ) {
        stream->flags |= __FILE_ERROR;
        return 0;
    }

abort:
    return size ? res / size : 0;
}
