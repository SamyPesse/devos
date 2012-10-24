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
#ifndef SYSTEM_H
#define SYSTEM_H

#include <runtime/types.h>
#include <core/env.h>
#include <core/user.h>


class System
{
	public:
		System();
		~System();
		
		void	init();
		char*	getvar(char* name);
		
		
		void	addUserToList(User* us);
		
		User*	getUser(char* nae);
		
		int		login(User* us,char* pass);
		u32 	isRoot();			//renvoie 1 si root
		
		
	private:
		User*		listuser;
	
		File*		var;
		
		User*		actual;
		User*		root;
		
		Variable*	uservar;
};

extern System		sys;
#endif
