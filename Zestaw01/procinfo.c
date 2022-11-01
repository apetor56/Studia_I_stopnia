#define _XOPEN_SOURCE 500

#include "procinfo.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int procinfo(const char* name)
{
	printf("name: %s, UID: %d, GID: %d, PID: %d, PPID: %d, PGID: %d \n",
			name, getuid(), getgid(), getpid(), getppid(), getpgid(0));

	return 0;
}
