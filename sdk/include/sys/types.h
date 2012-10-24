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

#ifndef _SYS_TYPES_H_
#define _SYS_TYPES_H_

#include <stdint.h>

#define __need_size_t
#include <stddef.h>

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif /* __cplusplus */
#endif /* NULL */

#define INFINITE_TIMEOUT 18446744073709551615ULL

typedef unsigned char u_char;

typedef int ssize_t;
typedef int pid_t;
typedef int64_t ino_t;
typedef int64_t off_t;
typedef int dev_t;
typedef int mode_t;
typedef int nlink_t;
typedef int uid_t;
typedef int gid_t;
typedef int blksize_t;
typedef int64_t blkcnt_t;

#endif /* _SYS_TYPES_H_ */
