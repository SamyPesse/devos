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
#ifndef API_H
#define API_H

//posix
void call_open();
void call_close();
void call_read();
void call_write();
void call_sbrk();
void call_ioctl();
void call_exit();
void call_execv();
void call_symlink();
void call_getdents();
void call_wait();
void call_dup2();
void call_fork();
void call_chdir();
void call_mmap();


//koala
void call_loadmodule();
void call_login();
void call_newuser();


#endif
