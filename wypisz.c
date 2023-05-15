#include <stdio.h>
#include <unistd.h>

int main() {
    uid_t UID = getuid();
    gid_t GID = getgid();
    pid_t PID = getpid();
    pid_t PPID = getppid();
    pid_t PGID = getpgid(PID);
    printf("UID %d / GID %d / PID %d / PPID %d / PGID %d\n", UID, GID, PID, PPID, PGID);
}