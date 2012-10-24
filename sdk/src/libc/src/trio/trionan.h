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

#ifndef TRIO_TRIONAN_H
#define TRIO_TRIONAN_H

#include "triodef.h"

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(TRIO_PUBLIC_NAN)
# if !defined(TRIO_PUBLIC)
#  define TRIO_PUBLIC
# endif
# define TRIO_PUBLIC_NAN TRIO_PUBLIC
#endif
  
enum {
  TRIO_FP_INFINITE,
  TRIO_FP_NAN,
  TRIO_FP_NORMAL,
  TRIO_FP_SUBNORMAL,
  TRIO_FP_ZERO
};

/*************************************************************************
 * Dependencies
 */

#if defined(TRIO_EMBED_NAN)

/*
 * The application that trionan is embedded in must define which functions
 * it uses.
 *
 * The following resolves internal dependencies.
 */
  
# if defined(TRIO_FUNC_ISNAN) \
  || defined(TRIO_FUNC_ISINF)
#  if !defined(TRIO_FUNC_FPCLASSIFY_AND_SIGNBIT)
#   define TRIO_FUNC_FPCLASSIFY_AND_SIGNBIT
#  endif
# endif

# if defined(TRIO_FUNC_NAN)
#  if !defined(TRIO_FUNC_PINF)
#   define TRIO_FUNC_PINF
#  endif
# endif
  
# if defined(TRIO_FUNC_NINF)
#  if !defined(TRIO_FUNC_PINF)
#   define TRIO_FUNC_PINF
#  endif
# endif

#else

/*
 * When trionan is not embedded all all functions are defined.
 */
  
# define TRIO_FUNC_NAN
# define TRIO_FUNC_PINF
# define TRIO_FUNC_NINF
# define TRIO_FUNC_NZERO
# define TRIO_FUNC_ISNAN
# define TRIO_FUNC_ISINF
# define TRIO_FUNC_ISFINITE
# define TRIO_FUNC_SIGNBIT
# define TRIO_FUNC_FPCLASSIFY
# define TRIO_FUNC_FPCLASSIFY_AND_SIGNBIT
  
#endif

/*************************************************************************
 * Functions
 */

/*
 * Return NaN (Not-a-Number).
 */
#if defined(TRIO_FUNC_NAN)
TRIO_PUBLIC_NAN double
trio_nan
TRIO_PROTO((void));
#endif

/*
 * Return positive infinity.
 */
#if defined(TRIO_FUNC_PINF)
TRIO_PUBLIC_NAN double
trio_pinf
TRIO_PROTO((void));
#endif

/*
 * Return negative infinity.
 */
#if defined(TRIO_FUNC_NINF)
TRIO_PUBLIC_NAN double
trio_ninf
TRIO_PROTO((void));
#endif

/*
 * Return negative zero.
 */
#if defined(TRIO_FUNC_NZERO)
TRIO_PUBLIC_NAN double
trio_nzero
TRIO_PROTO((TRIO_NOARGS));
#endif

/*
 * If number is a NaN return non-zero, otherwise return zero.
 */
#if defined(TRIO_FUNC_ISNAN)
TRIO_PUBLIC_NAN int
trio_isnan
TRIO_PROTO((double number));
#endif

/*
 * If number is positive infinity return 1, if number is negative
 * infinity return -1, otherwise return 0.
 */
#if defined(TRIO_FUNC_ISINF)
TRIO_PUBLIC_NAN int
trio_isinf
TRIO_PROTO((double number));
#endif

/*
 * If number is finite return non-zero, otherwise return zero.
 */
#if defined(TRIO_FUNC_ISFINITE)
TRIO_PUBLIC_NAN int
trio_isfinite
TRIO_PROTO((double number));
#endif

#if defined(TRIO_FUNC_SIGNBIT)
TRIO_PUBLIC_NAN int
trio_signbit
TRIO_PROTO((double number));
#endif

#if defined(TRIO_FUNC_FPCLASSIFY)
TRIO_PUBLIC_NAN int
trio_fpclassify
TRIO_PROTO((double number));
#endif

#if defined(TRIO_FUNC_FPCLASSIFY_AND_SIGNBIT)
TRIO_PUBLIC_NAN int
trio_fpclassify_and_signbit
TRIO_PROTO((double number, int *is_negative));
#endif

#ifdef __cplusplus
}
#endif

#endif /* TRIO_TRIONAN_H */
