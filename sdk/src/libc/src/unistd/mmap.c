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
#include <unistd.h>

#include <os.h>

void * mmap (void *addr,size_t len,int prot,int flags,int fd,off_t offset){
	return (void*)syscall5(SYS_mmap,(uint32_t) len, (uint32_t) prot, (uint32_t) flags,(uint32_t) fd,(uint32_t) offset);
}

