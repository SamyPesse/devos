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

#ifndef _SYS_SELECT_H_
#define _SYS_SELECT_H_

#include <sys/time.h>
#include <sys/types.h>

#define FD_ZERO(set) \
    memset( (set)->fds, 0, 1024 / 32 );

#define FD_CLR(fd,set) \
    (set)->fds[fd/32] &= ~(1<<(fd%32));

#define FD_SET(fd,set) \
    (set)->fds[fd/32] |= (1<<(fd%32));

#define FD_ISSET(fd,set) \
    ((set)->fds[fd/32] & (1<<(fd%32)))

typedef struct fd_set {
    uint32_t fds[ 1024 / 32 ];
} fd_set;

int select( int fds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, struct timeval* timeout );

#endif // _SYS_SELECT_H_
