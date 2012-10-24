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
 

#include <sys/time.h>

#include <os.h>

time_t time( time_t* t ) {
    int ret;
    uint64_t time;

    ret = syscall1( SYS_get_system_time, ( int )&time );

    if ( ret < 0 ) {
        time = 0;
    } else {
        time /= 1000000;
    }

    if ( t != NULL ) {
        *t = time;
    }

    return time;
}
