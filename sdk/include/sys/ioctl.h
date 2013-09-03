

#ifndef _SYS_IOCTL_H_
#define _SYS_IOCTL_H_

#include <sys/types.h>

#include <api/dev/ioctl.h>

int ioctl( int fd, int request, ... );

#endif /* _SYS_IOCTL_H_ */
