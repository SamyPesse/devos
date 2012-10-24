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
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> /* NULL */

#include <getopt.h>
#include "getopt_int.h"

int getopt_long( int argc, char* const * argv, const char* shortopts,
                 const struct option* longopts, int* longind ){
    return _getopt_internal (argc, argv, shortopts, longopts, longind, 0);
}
