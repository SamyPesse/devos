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
 

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

static char ttyname_buffer[ 128 ];

int ttyname_r( int fd, char* buf, size_t buflen ) {
    int dir;
    int error;
    int found;

    struct stat st;
    struct dirent entry;

    error = fstat( fd, &st );

    if ( error < 0 ) {
        return -1;
    }

    dir = open( "/device/terminal", O_RDONLY );

    if ( dir < 0 ) {
        return -1;
    }

    found = 0;

    while ( getdents( dir, &entry, sizeof( struct dirent ) ) == 1 ) {
        if ( entry.d_ino == st.st_ino ) {
            snprintf( buf, buflen, "/device/terminal/%s", entry.d_name );
            found = 1;
            break;
        }
    }

    close( dir );

    if ( !found ) {
        return -1;
    }

    return 0;
}

char* ttyname( int fd ) {
    int error;

    error = ttyname_r( fd, ttyname_buffer, sizeof( ttyname_buffer ) );

    if ( error < 0 ) {
        return NULL;
    }

    return ttyname_buffer;
}
