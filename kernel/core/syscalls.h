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
#ifndef SYSCALL_H
#define SYSCALL_H

#include <core/file.h>
#include <runtime/list.h>


#define NB_SYSCALLS	100


typedef void (*syscall_handler)(void);

class Syscalls 
{
	public:
		void	init();
		void	add(u32 num,syscall_handler h);
		void	call(u32 num);
		
	protected:
		syscall_handler		calls[NB_SYSCALLS];

};

extern Syscalls	syscall;

#endif
