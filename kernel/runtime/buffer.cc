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
#include <runtime/buffer.h>



Buffer::Buffer(char* n,u32 siz){
	map=(char*)kmalloc(siz);
	size=siz;
	memcpy(map,n,siz);
}

Buffer::Buffer(){
	size=0;
	map=NULL;
}

Buffer::~Buffer(){
	if (map!=NULL)
		kfree(map);
}

void Buffer::add(u8* c,u32 s){
	char* old=map;
	map=(char*)kmalloc(size+s);
	memcpy(map,old,size);
	kfree(old);
	memcpy((char*)(map+size),(char*)c,s);
	size=size+s;
}

u32 Buffer::get(u8* c,u32 s){
	if( s>size)
		s=size;
	memcpy((char*)c,(char*)(map+(size-s)),s);
	char*old=map;
	map=(char*)kmalloc(size-s);
	memcpy(map,old,(size-s));
	kfree(old);
	size=size-s;
	return s;
}

u32 Buffer::isEmpty(){
	if (size==0)
		return 1;
	else
		return 0;
}

void Buffer::clear(){
	size=0;
	if (map!=NULL)
		kfree(map);	
}

Buffer &Buffer::operator>>(char *c)
{
	memcpy(c,map,size);
	return *this;
}
