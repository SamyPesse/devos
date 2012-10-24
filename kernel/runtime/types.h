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
#ifndef TYPES_H
#define TYPES_H

/*
 *	General C-Types
 */
typedef unsigned char 	u8;
typedef unsigned short 	u16;
typedef unsigned int 	u32;
typedef unsigned long long 	u64;


typedef signed char 	s8;
typedef signed short 	s16;
typedef signed int 		s32;
typedef signed long long	s64;


typedef unsigned char u_char;

typedef int ssize_t;
typedef int pid_t;
typedef s64 ino_t;
typedef s64 off_t;
typedef int dev_t;
typedef int mode_t;
typedef int nlink_t;
typedef int uid_t;
typedef int gid_t;
typedef int blksize_t;
typedef s64 blkcnt_t;
#define time_t s64

struct stat_fs {
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
    nlink_t st_nlink;
    uid_t st_uid;
    gid_t st_gid;
    dev_t st_rdev;
    off_t st_size;
    blksize_t st_blksize;
    blkcnt_t st_blocks;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
};


/*
* Return code
*/
enum{
	RETURN_OK=0,
	NOT_DEFINED=-1, //If not implemented
	ERROR_MEMORY=-2,
	PARAM_NULL=-3,
	ERROR_PARAM=-4,
	RETURN_FAILURE=-128 //Added by NoMaintener aka William. In case of error
};
 
 
/*
 *	Interruption handler
 */
typedef void (*int_handler)(void);


#define NULL 0
#define true 1
#define false 0

#endif
