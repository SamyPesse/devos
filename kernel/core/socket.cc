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



Socket::~Socket(){
	
}

Socket::Socket(char* n) : File(n,TYPE_FILE)
{
	fsm.addFile("/sys/sockets/",this);
}

u32	Socket::open(u32 flag){
	return RETURN_OK;
}

u32	Socket::close(){
	return RETURN_OK;
}

u32	Socket::read(u8* buffer,u32 size){
	return NOT_DEFINED;
}

u32	Socket::write(u8* buffer,u32 size){
	return NOT_DEFINED;
}

u32	Socket::ioctl(u32 id,u8* buffer){
	return NOT_DEFINED;
}

u32	Socket::remove(){
	delete this;
}

void Socket::scan(){

}

