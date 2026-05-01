#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <sys/syscall.h>

int sysclone() {
return syscall(SYS_clone,   CLONE_FILES | SIGCHLD | CLONE_FS,NULL);
}
