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
#ifndef __API_FB__
#define __API_FB__

struct fb_info{
	unsigned int		w;	//largeur
	unsigned int		h;	//hauteur
	char				bpp;	//bit per pixel
	char				state;	//etat de la carte
	unsigned int*		vmem;	//video memory
};

enum{
	FB_NOT_ACTIVE=0,
	FB_ACTIVE=1,
};

#define API_FB_IS_AVAILABLE			0x801
#define API_FB_GET_INFO				0x802	//info actuel
#define API_FB_GET_BINFO			0x803	//meilleur info
#define API_FB_SET_INFO				0x804


#endif
