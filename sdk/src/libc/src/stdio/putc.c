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
 

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int putc( int c, FILE* stream ) {
    return fputc( c, stream );
}



int 	support_vfprintf(FILE* stream, const char* format, va_list ap);

int vfprintf(FILE* stream, const char* format, va_list arg)
{
	return support_vfprintf( stream, format, arg );
}

int printf(const char* format, ...)
{
	int rc;
	va_list ap;
	va_start(ap, format);
		rc = vfprintf( stdout, format, ap );
	va_end(ap);
  return rc;
}


int fprintf(FILE*stream,const char* format, ...)
{
	int rc;
	va_list ap;
	va_start(ap, format);
		rc = vfprintf(stream, format, ap );
	va_end(ap);
  return rc;
}
