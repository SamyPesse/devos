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
 

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include <os.h>

ssize_t readlink( const char* path, char* buf, size_t bufsiz ) {
    int error;

    error = syscall3( SYS_readlink, ( int )path, ( int )buf, bufsiz );

    if ( error < 0 ) {
        errno = -error;
        return -1;
    }

    return error;
}
