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
 

#include <string.h>
#include <stdarg.h>


char* strcpy( char* d, const char* s ) {
    char* tmp = d;

    while ( ( *d++ = *s++ ) != 0 ) ;

    return tmp;
}

int support_vsprintf(char* buffer, const char* format, va_list ap);

int vsprintf(char* s, const char* format, va_list arg)
{
	return support_vsprintf( s, format, arg );
}


int sprintf(char *buffer, const char* format, ...)
{
	int rc;
	va_list ap;
	va_start(ap, format);
		rc = vsprintf( buffer, format, ap );
	va_end(ap);
   return 0;

}

