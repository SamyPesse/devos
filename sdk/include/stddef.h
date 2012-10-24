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
#ifndef _STDDEF_H
#define _STDDEF_H

#ifndef	NULL
#define NULL		0
#endif


#ifndef _HAVE_PTRDIFF_T
#define _HAVE_PTRDIFF_T
typedef signed long int	ptrdiff_t;
#endif

#ifndef _HAVE_SIZE_T
#define _HAVE_SIZE_T
//typedef	unsigned int	size_t;
typedef long unsigned int size_t;
#endif


#if ( (! defined _HAVE_WCHAR_T) && (! defined __cplusplus ) )
#define _HAVE_WCHAR_T
typedef int	wchar_t;
#endif

#define offsetof(struct_type, member) \
          (size_t) &(((struct_type *)0)->member)
          
/*#define offsetof(type, memberdesig)	\
			((const unsigned int)((ptrdiff_t)&(type.memberdesig) - (ptrdiff_t)&type))
*/

#endif

