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
#include <fcntl.h>
#include <unistd.h>

int __parse_mode( const char* mode );

FILE* freopen( const char* path, const char* mode, FILE* stream ) {
    int flags;

    if ( stream == NULL ) {
        errno = -EINVAL;
        return NULL;
    }

    flags = __parse_mode( mode );

    fflush( stream );
    close( stream->fd );

    stream->fd = open( path, flags, 0666 );

    if ( stream->fd != -1 ) {
        stream->flags = 0;

        switch ( flags & 3 ) {
          case O_RDWR :   stream->flags |= ( __FILE_CAN_READ | __FILE_CAN_WRITE ); break;
          case O_RDONLY : stream->flags |= __FILE_CAN_READ; break;
          case O_WRONLY : stream->flags |= __FILE_CAN_WRITE; break;
        }
    }

    return stream;
}
