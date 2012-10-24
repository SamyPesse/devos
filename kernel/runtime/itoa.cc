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



/*
 * Convertit un nombre en chaine de caractére
 */
extern "C" {
	void itoa(char *buf, unsigned long int n, int base)
	{
		unsigned long int tmp;
		int i, j;

		tmp = n;
		i = 0;

		do {
			tmp = n % base;
			buf[i++] = (tmp < 10) ? (tmp + '0') : (tmp + 'a' - 10);
		} while (n /= base);
		buf[i--] = 0;

		for (j = 0; j < i; j++, i--) {
			tmp = buf[j];
			buf[j] = buf[i];
			buf[i] = tmp;
		}
	}
}

