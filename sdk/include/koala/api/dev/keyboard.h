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
#ifndef __API_KEYBOARD__
#define __API_KEYBOARD__


//keyboard
enum {
    KEY_TAB = 7,
    KEY_BACKSPACE = 8,
    KEY_ENTER = 10,
    KEY_ESCAPE = 27,
    KEY_F1 = 255,
    KEY_F2 = 254,
    KEY_F3 = 253,
    KEY_F4 = 252,
    KEY_F5 = 251,
    KEY_F6 = 250,
    KEY_F7 = 249,
    KEY_F8 = 248,
    KEY_F9 = 247,
    KEY_F10 = 246,
    KEY_F11 = 245,
    KEY_F12 = 244
};

#define TABLE_KEYBOARD_SIZE			388

#define API_KEYBOARD_SET_TABLE		0x4122

#endif
