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
#ifndef USER_H
#define USER_H

#include <core/file.h>
#include <runtime/list.h>


enum {
	USER_ROOT,	//root
	USER_NORM	//utilisateur normal
};

class User : public File
{
	public:
		User(char* n);
		~User();
		
		u32		open(u32 flag);
		u32		close();
		u32		read(u8* buffer,u32 size);
		u32		write(u8* buffer,u32 size);
		u32		ioctl(u32 id,u8* buffer);
		u32		remove();
		void	scan();
		
		
		void	setPassword(char *n);
		char*	getPassword();
		
		User*	getUNext();
		void	setUNext(User* us);
		
		void	setUType(u32 t);
		u32		getUType();
		
	protected:
		u32		utype;
	
		User*	unext;
		char	password[512];
		
};

#endif
