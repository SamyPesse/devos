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
#ifndef __DOS_PARTITION__
#define __DOS_PARTITION__

#include <runtime/types.h>
#include <core/file.h>
#include <io.h>

#define DOS_PART_1	0x01BE
#define DOS_PART_2	0x01CE
#define DOS_PART_3	0x01DE
#define DOS_PART_4	0x01EE

struct dos_partition {
	u8 bootable;			/* 0 = no, 0x80 = bootable */
	u8 s_head;				/* Starting head */
	u16 s_sector:6;			/* Starting sector */
	u16 s_cyl:10;			/* Starting cylinder */
	u8 id;					/* System ID */
	u8 e_head;				/* Ending Head */
	u16 e_sector:6;			/* Ending Sector */
	u16 e_cyl:10;			/* Ending Cylinder */
	u32 s_lba;				/* Starting LBA value */
	u32 size;				/* Total Sectors in partition */
} __attribute__ ((packed));
 
/*
 *	Driver class
 */
class DosPartition : public Device
{
	public:
		DosPartition(char* n,File* dev,u32 num);
		~DosPartition();
		
		
		u32		open(u32 flag);
		u32		close();
		u32		read(u32 pos,u8* buffer,u32 sizee);
		u32		write(u32 pos,u8* buffer,u32 sizee);
		u32		ioctl(u32 id,u8* buffer);
		u32		remove();
		void	scan();
		

	private:
		u32 			numpart;
		dos_partition*	partition_info;
};

#endif
