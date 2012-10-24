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
 
#ifndef _TIME_INT_H_
#define _TIME_INT_H_
#include <time.h> /* Time structures */

#define EPOCH 1970 /* Counting only time elapsed since 1 Jan 1970 */

#define SECONDS_PER_DAY 86400
#define SECONDS_PER_HOUR 3600
#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24

/* The number of days that come before each month */
extern const unsigned short int monthdays[ 13 ]; /* Common year */
extern const unsigned short int monthdays2[ 13 ]; /* Leap year */
/* The number of days passed in N years after 1970 or any leap year */
extern const unsigned short int sumofdays[ 60 ];

/* Converts a UNIX timestamp to a broken-down time */
int _gmtime(time_t time, tm_t* ret);

/* Returns the day of the week, 0=Sunday */
int dayofweek(int year, int month, int day);

/* Returns the number of days since the epoch */
int daysdiff(int year, int month, int day);

#endif // _TIME_INT_H_
