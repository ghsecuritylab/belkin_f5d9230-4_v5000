/* Copyright (C) 2004       Manuel Novoa III    <mjn3@codepoet.org>
 *
 * GNU Library General Public License (LGPL) version 2 or later.
 *
 * Dedicated to Toni.  See uClibc/DEDICATION.mjn3 for details.
 */

#include "_stdio.h"

#ifdef __DO_UNLOCKED

weak_alias(__ferror_unlocked,ferror_unlocked);
#ifndef __UCLIBC_HAS_THREADS__
weak_alias(__ferror_unlocked,ferror);
#endif

int __ferror_unlocked(register FILE *stream)
{
	__STDIO_STREAM_VALIDATE(stream);

	return __FERROR_UNLOCKED(stream);
}

#elif defined __UCLIBC_HAS_THREADS__

int ferror(register FILE *stream)
{
	int retval;
	__STDIO_AUTO_THREADLOCK_VAR;

	__STDIO_AUTO_THREADLOCK(stream);

	__STDIO_STREAM_VALIDATE(stream);

	retval = __FERROR_UNLOCKED(stream);

	__STDIO_AUTO_THREADUNLOCK(stream);

	return retval;
}

#endif
