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
 

unsigned int _seed = 0xDEADBEEF;

long int random( void ) {
    unsigned int next = _seed;
    unsigned long int result;

    next *= 1103515245;
    next += 12345;
    result = ( unsigned int  ) ( next / 65536 ) % 2048;

    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= ( unsigned int ) ( next / 65536 ) % 1024;

    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= ( unsigned int ) ( next / 65536 ) % 1024;

    _seed = next;

    return result;
}
