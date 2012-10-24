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
 

#ifndef _UTIME_H_
#define _UTIME_H_

#include <time.h>

struct utimbuf {
    time_t actime; /* access time */
    time_t modtime; /* modification time */
};

int utime( const char* filename, const struct utimbuf* times );
int utimes( const char* filename, const timeval_t times[2] );

#endif // _UTIME_H_
