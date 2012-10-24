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
#ifndef __X86Serial__
#define __X86Serial__

#include <runtime/types.h>
#include <core/device.h>
#include <io.h>

#define COM1	   0x3F8	
#define IRQ_COM1   4
#define COM2 	   2F8 	
#define IRQ_COM2   3
#define COM3 	   3E8 	
#define IRQ_COM3   4
#define COM4 	   2E8 	
#define IRQ_COM4   3


class X86Serial : public Device
{
	public:
		X86Serial(char* n);
		~X86Serial();
		
		void	putc(char c);
		char 	getc();
		
		u32		open(u32 flag);
		u32		close();
		u32		read(u32 pos,u8* buffer,u32 size);
		u32		write(u32 pos,u8* buffer,u32 size);
		u32		ioctl(u32 id,u8* buffer);
		u32		remove();
		void	scan();
		
	private:
		static u8 init_serial;
};

#endif
