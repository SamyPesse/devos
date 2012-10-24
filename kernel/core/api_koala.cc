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

/* Ce fichier designe tous les appels systèmes specifique à koala */ 

/*
 *	int loadmodule(char* dev,char* module,char* devname);
 */
void call_loadmodule(){
	char* todev=(char*)arch.getArg(0);
	char* modulename=(char*)arch.getArg(1);
	char* devname=(char*)arch.getArg(2);
	u32	  flags=arch.getArg(3);
	File* fp=modm.install(todev,modulename,flags,devname);
	if (fp==NULL)
		arch.setRet(-1);
	else
		arch.setRet(1);
}

/*
 *	int login(char* name,char* pass);
 */
void call_login(){
	char* name=(char*)arch.getArg(0);
	char* pass=(char*)arch.getArg(1);
	
	User*us=sys.getUser(name);
	if (us==NULL){
		io.print("error can't find %s\n",name);
		arch.setRet(-1);
		return;
	}
	
	u32 ret=(u32)sys.login(us,pass);
	arch.setRet(ret);
}

/*
 *	int newuser(char* name,char* pass);
 */
void call_newuser(){
	char* name=(char*)arch.getArg(0);
	char* pass=(char*)arch.getArg(1);
	u32 ret=1;
	
	User* n= new User(name);
	n->setPassword(pass);
	
	arch.setRet(ret);
}

