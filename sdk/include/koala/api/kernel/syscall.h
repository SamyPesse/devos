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

#ifndef _OS_SYSCALL_H_
#define _OS_SYSCALL_H_


int syscall0( int number );
int syscall1( int number, unsigned int p1 );
int syscall2( int number, unsigned int p1, unsigned int p2 );
int syscall3( int number, unsigned int p1, unsigned int p2, unsigned int p3 );
int syscall4( int number, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4 );
int syscall5( int number, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5 );

#endif
