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

#include "stdio_internal.h"

int fputc( int c, FILE* stream ) {
    /* Check if we can write to the stream */

    if ( ( ( stream->flags & __FILE_CAN_WRITE ) == 0 ) ||
         ( __set_stream_flags( stream, 0 ) ) ) {
        stream->flags |= __FILE_ERROR;
        return EOF;
    }

    /* Make sure we have free space in the buffer */

    if ( stream->buffer_pos >= stream->buffer_size - 1 ) {
        if ( fflush( stream ) ) {
            stream->flags |= __FILE_ERROR;
            return EOF;
        }
    }

    if ( stream->flags & __FILE_NOBUF ) {
        if ( write( stream->fd, &c, 1 ) != 1 ) {
            stream->flags |= __FILE_ERROR;
            return EOF;
        }

        return 0;
    }

    stream->buffer[ stream->buffer_pos++ ] = c;

    if ( ( ( stream->flags & __FILE_BUFLINEWISE ) && ( c == '\n' ) ) ||
         ( stream->flags & __FILE_NOBUF ) ) {
        if ( fflush( stream ) ) {
            stream->flags |= __FILE_ERROR;
            return EOF;
        }
    }

    return 0;
}
