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
#ifndef DEVICE_H
#define DEVICE_H

#include <core/file.h>
#include <runtime/list.h>


class Device : public File
{
	public:
		Device(char* n);
		~Device();
		
		virtual u32		open(u32 flag);
		virtual u32		close();
		virtual u32		read(u8* buffer,u32 size);
		virtual u32		write(u8* buffer,u32 size);
		virtual u32		ioctl(u32 id,u8* buffer);
		virtual u32		remove();
		virtual void	scan();
		
		
		
		
		
	protected:

};

#endif
