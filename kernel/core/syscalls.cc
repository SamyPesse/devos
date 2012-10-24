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
#include <os.h>
#include <api.h>

#include <api/kernel/syscall_table.h>

#define sysc(a,h) add(a,(syscall_handler)h)

void Syscalls::init(){
	int i;
	for (i=0;i<NB_SYSCALLS;i++)
		calls[i]=NULL;
	sysc(SYS_open,		&call_open);
	sysc(SYS_close,		&call_close);
	sysc(SYS_read,		&call_read);
	sysc(SYS_write,		&call_write);
	sysc(SYS_sbrk,		&call_sbrk);
	sysc(SYS_ioctl,		&call_ioctl);
	sysc(SYS_exit,		&call_exit);
	sysc(SYS_execve,	&call_execv);
	sysc(SYS_symlink,	&call_symlink);
	sysc(SYS_getdents,	&call_getdents);
	sysc(SYS_wait4,		&call_wait);
	sysc(SYS_dup2,		&call_dup2);
	sysc(SYS_fork,		&call_fork);
	sysc(SYS_chdir,		&call_chdir);
	sysc(SYS_mmap,		&call_mmap);
	
	sysc(SYS_login,		&call_login);
	sysc(SYS_loadmod,	&call_loadmodule);
	sysc(SYS_newuser,	&call_newuser);
}


void Syscalls::add(u32 num,syscall_handler h){
	calls[num]=h;
}

void Syscalls::call(u32 num){
	if (calls[num]!=NULL)
		calls[num]();
}
