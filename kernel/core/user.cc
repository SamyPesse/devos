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



User::~User(){
	
}

User::User(char* n) : File(n,TYPE_FILE)
{
	fsm.addFile("/sys/usr/",this);
	unext=0;
	sys.addUserToList(this);
	utype=USER_NORM;
	memset(password,0,512);
}

u32	User::open(u32 flag){
	return RETURN_OK;
}

u32	User::close(){
	return RETURN_OK;
}

u32	User::read(u8* buffer,u32 size){
	return NOT_DEFINED;
}

u32	User::write(u8* buffer,u32 size){
	return NOT_DEFINED;
}

u32	User::ioctl(u32 id,u8* buffer){
	return NOT_DEFINED;
}

u32	User::remove(){
	delete this;
}

void User::scan(){

}

void User::setPassword(char *n){
	if (n!=NULL)
		return;
	memset(password,0,512);
	strcpy(password,n);
}

char* User::getPassword(){
	if (password[0]=0)
		return NULL;
	else
		return password;
}

User* User::getUNext(){
	return unext;
}

void User::setUNext(User* us){
	unext=us;
}

void User::setUType(u32 t){
	utype=t;
}

u32	User::getUType(){
	return utype;
}

