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
#ifndef MYOS_H
#define MYOS_H

#include <config.h>
#include <kernel.h>


typedef File* (*device_driver)	(char* name,u32 flag,File* dev);

struct module_class{
	int					module_type;
	char*			module_name;
	char*			class_name;
	device_driver	drive;
};




/*
 *	Module Macro
 */
#define MODULE_DEVICE		0
#define MODULE_FILESYSTEM	1
#define module(name,type,classe,mknod)	module_class classe##_module={type,\
																name, \
																#classe, \
																(device_driver)mknod};	

#define import_module(classe) 	extern module_class  classe##_module

#define run_module_builder	module_class* module_builder[]=
#define build_module(classe) 	&classe##_module
#define end_module() 		NULL

#define std_buildin_module	void Module::init()
#define	run_module(n,m,f) createDevice(#m,#n,f);

/*
 *	Asm Macro
 */
#define asm 		__asm__
#define asmv 		__asm__ __volatile__



#endif
