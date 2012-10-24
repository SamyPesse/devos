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
#include <null.h>

#include <api/dev/ioctl.h>

File* null_mknod(char* name,u32 flag,File* dev){
	Null* cons=new Null(name);
	return cons;
}

module("module.null",MODULE_DEVICE,Null,null_mknod)

Null::~Null(){
	
}

Null::Null(char* n) : Device(n)
{

}

void Null::scan(){

}

u32	Null::close(){
	return RETURN_OK;
}

u32	Null::open(u32 flag){
	return RETURN_OK;
}

u32	Null::read(u32 pos,u8* buffer,u32 size){
	memset((char*)buffer,0,size);
	return size;
}

u32	Null::write(u32 pos,u8* buffer,u32 size){
	return size;
}

u32	Null::ioctl(u32 id,u8* buffer){
	u32 ret=0;
	switch (id){
		case DEV_GET_TYPE:
			ret=DEV_TYPE_TTY;
			break;
			
		case DEV_GET_STATE:
			ret=DEV_STATE_OK;
			break;
			
		case DEV_GET_FORMAT:
			ret=DEV_FORMAT_CHAR;
			break;
	
		default:
			ret=NOT_DEFINED;
	}
	return ret;
}

u32	Null::remove(){
	delete this;
	return RETURN_OK;
}
