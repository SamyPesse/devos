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
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <runtime/types.h>
#include <core/file.h>


class Filesystem
{
	public:
		Filesystem();
		~Filesystem();
		
		void 	init();
		void	mknod(char* module,char* name,u32 flag);
		
		File* 	path(char* p);
		File* 	path_parent(char* p,char *fname);
		
		u32		link(char* fname,char *newf);
		
		
		u32 	addFile(char* dir,File* fp);
		
		File* 	pivot_root(File* targetdir);
		
		File*	getRoot();
		
	private:
		File*	root;
		File*	dev;
		File*	var;
};

extern Filesystem		fsm;
#endif
