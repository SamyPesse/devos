/**
 *	Koala Operating System
 *	Copyright (C) 2010 - 2011 Samy Pessé
 *	
 *	This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
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
#ifndef CONFIG_H
#define CONFIG_H

#define KERNEL_NAME		"Koala"		/* nom du noyau */
#define KERNEL_VERSION	"12.4"		/* version du noyau */
#define KERNEL_DATE		__DATE__
#define KERNEL_TIME		__TIME__
#define KERNEL_LICENCE	"Copyright (c) 2010, Samy Pesse (GPLv3)"	/* licence et copyright */
#define KERNEL_COMPUTERNAME	"koala-pc"	/* nom par default du pc */

/* identifiant du processeur */
#ifdef __x86__
#define KERNEL_PROCESSOR_IDENTIFIER "x86"
#else
#defien KERNEL_PROCESSOR_IDENTIFIER "(null)"
#endif

/* nombre maximal de fichier pouvant etre ouvert */
#define CONFIG_MAX_FILE	32

#endif
