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
#include <dospartition.h>

/*
 *	Flag indique le numero de partition
 */
File* dospartition_mount(char* name,u32 flag,File* dev){
	DosPartition* dos=new DosPartition(name,dev,flag);
	return dos;
}

module("module.dospartition",MODULE_FILESYSTEM,DosPartition,dospartition_mount)

DosPartition::~DosPartition(){
	
}

DosPartition::DosPartition(char* n,File* dev,u32 num) : Device(n)
{
	device=dev;
	numpart=num;
	partition_info=NULL;
	if (device!=NULL){
		partition_info=(dos_partition*)kmalloc(sizeof(dos_partition));
		device->read((u32)(DOS_PART_1+(u32)(numpart*sizeof(dos_partition))),
					 (u8*)partition_info,
					 sizeof(dos_partition));	
	}
}

void DosPartition::scan(){
	
}

u32	DosPartition::close(){
	if (partition_info!=NULL && device!=NULL){
		return device->close();
	}
	return ERROR_PARAM;
}

u32	DosPartition::open(u32 flag){
	if (partition_info!=NULL && device!=NULL){
		return device->open(flag);
	}
	return ERROR_PARAM;
}

u32	DosPartition::read(u32 pos,u8* buffer,u32 sizee){
	if (partition_info!=NULL && device!=NULL){
		return device->read(((partition_info->s_lba)*512)+pos,buffer,sizee);
	}
	return ERROR_PARAM;
}

u32	DosPartition::write(u32 pos,u8* buffer,u32 sizee){
	if (partition_info!=NULL && device!=NULL){
		return device->write((partition_info->s_lba*512)+pos,buffer,sizee);
	}
	return ERROR_PARAM;
}

u32	DosPartition::ioctl(u32 id,u8* buffer){
	if (partition_info!=NULL && device!=NULL){
		return device->ioctl(id,buffer);
	}
	return ERROR_PARAM;
}

u32	DosPartition::remove(){
	delete this;
	return RETURN_OK;
}


