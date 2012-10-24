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
#ifndef BUFFER_H
#define BUFFER_H


class Buffer
{
	public:
		Buffer(char* n,u32 siz);
		Buffer();
		~Buffer();
		
		void	add(u8* c,u32 s);
		u32	get(u8* c,u32 s);
		void	clear();
		u32		isEmpty();
		
		
		Buffer &operator>>(char *c);
		
		
		u32 	size;
		char*	map;
	
};


#endif
