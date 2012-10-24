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

int fgetc( FILE* stream ) {
    unsigned char c;

    /* Check if we can read from the stream */

    if ( ( ( stream->flags & __FILE_CAN_READ ) == 0 ) ||
         ( __set_stream_flags( stream, __FILE_BUFINPUT ) ) ) {
        stream->flags |= __FILE_ERROR;
        printf("EOF ! \n");
        return EOF;
    }

    /* Check the unget buffer */

    if ( stream->has_ungotten ) {
        stream->has_ungotten = 0;
        printf("un get ! \n");
        return stream->unget_buffer;
    }

    /* Check the end of the file */

    if ( feof( stream ) ) {
		printf("EOF ! \n");
        return EOF;
    }

    /* Fill the buffer if it's empty */

    if ( stream->buffer_pos >= stream->buffer_data_size ) {
        ssize_t length;

        length = read( stream->fd, stream->buffer, stream->buffer_size );
        if ( length == 0 ) {
            stream->flags |= __FILE_EOF;
            printf("EOF ! \n");
            return EOF;
        } else if ( length < 0 ) {
            stream->flags |= __FILE_ERROR;
            printf("EOF ! \n");
            return EOF;
        }
        stream->buffer_pos = 0;
        stream->buffer_data_size = length;
    }

    /* Get one character from the buffer */

    c = stream->buffer[ stream->buffer_pos ];

    stream->buffer_pos++;

    return c;
}
