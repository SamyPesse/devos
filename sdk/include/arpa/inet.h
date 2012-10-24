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

#ifndef _ARPA_INET_H_
#define _ARPA_INET_H_

#include <netinet/in.h> /* struct in_addr */

int inet_aton( const char* cp, struct in_addr* inp );

in_addr_t inet_addr( const char* cp );

in_addr_t inet_network( const char* cp );

char* inet_ntoa( struct in_addr in );

struct in_addr inet_makeaddr( int net, int host );

in_addr_t inet_lnaof( struct in_addr in );

in_addr_t inet_netof( struct in_addr in );

#endif /* _ARPA_INET_H_ */
