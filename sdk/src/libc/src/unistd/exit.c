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
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include <os.h>

typedef void ( *atexit_func_t )( void );

static uint32_t atexit_count = 0;
static atexit_func_t atexit_functions[ ATEXIT_MAX ];

int atexit( void ( *function )( void ) ) {
    if ( atexit_count >= ATEXIT_MAX ) {
        return -1;
    }

    atexit_functions[ atexit_count++ ] = function;

    return 0;
}



void exit( int status ) {
    uint32_t i;

    for ( i = 0; i < atexit_count; i++ ) {
        atexit_functions[ i ]();
    }

    fflush( stdout );
    syscall1( SYS_exit, status );
	for (;;);
}
