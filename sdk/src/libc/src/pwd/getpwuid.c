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
 

#include <pwd.h>


typedef struct passwd_myos passwd_myos;
struct passwd_myos {
    char name[64];
    char password[64];
    int uid;
    int gid;
    char gecos[64];
    char dir[512];
    char shell[64];
};

extern struct passwd __tmp_passwd;

passwd_myos* myos_user_getID(int id);


struct passwd* getpwuid( uid_t uid ) {

	passwd_myos* pass=myos_user_getID(uid);
	if (pass==NULL)
		return NULL;
	
	build_tmp_passwd();
	return &__tmp_passwd;
}
