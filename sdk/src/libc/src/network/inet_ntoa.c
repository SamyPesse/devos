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
 

#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

char* inet_ntoa( struct in_addr in ) {
    unsigned int ip;
    static char __inet_ntoa_result[18];
    int i;
    uint8_t bytes[4];
    uint8_t* addrbyte;

    ip = in.s_addr;

    addrbyte = (uint8_t *)&ip;

    for(i = 0; i < 4; i++) {
        bytes[i] = *addrbyte++;
    }

    snprintf (__inet_ntoa_result, 18, "%d.%d.%d.%d", bytes[0], bytes[1], bytes[2], bytes[3]);

    return __inet_ntoa_result;
}
