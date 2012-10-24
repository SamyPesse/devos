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
#ifndef __API_IOCTL__
#define __API_IOCTL__


#define DEV_GET_TYPE		0x01	/* Renvoie le type de peripherique */
#define	DEV_GET_STATE		0x02	/* renvoie l'etat du peripherique */
#define	DEV_GET_FORMAT		0x03	/* renvoie le format du peripherique */

//Type de peripherique :
#define DEV_TYPE_TTY 0x01
#define DEV_TYPE_DISK 0x02
#define DEV_TYPE_FB 0x03
#define DEV_TYPE_HID 0x04 //Added by NoMaitener (aka William). HID stand for Human Interface Device

//Format du peripherique
#define DEV_FORMAT_CHAR 0x01
#define DEV_FORMAT_BLOCK 0x02
#define DEV_FORMAT_FB 0x03

//Etat du peripherique
#define DEV_STATE_OK 0x01
#define DEV_STATE_NOTREADY 0x02 //Added by NoMaitener (aka William). Discuss here of "NOTREADY"


#endif
