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
 

#ifndef _DIRENT_H_
#define _DIRENT_H_

#include <unistd.h>


typedef struct DIR {
    int fd;
    struct dirent entry;
} DIR;

DIR* opendir( const char* name );
int closedir( DIR* dir );

struct dirent* readdir( DIR* dir );
int readdir_r( DIR* dir, struct dirent* entry, struct dirent** result );

void rewinddir( DIR* dir );

#endif /* _DIRENT_H_ */
