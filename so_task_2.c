#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main (int argc, char *argv[]) {
    int stat_lock = 0;
    for (int i = 0; i < 3; i++) {
        switch (fork ()) {
            case -1:
                perror("Error occurred while forking");
            case 0:
                execl (argv[1], argv[1], NULL);
                perror("Error occurred while performing execl");
                break;
            default:
                if (wait(&stat_lock) == -1) {
                    perror ("Error occurred while waiting");
                }
        }
    }
    printf ("Parent process\n");
    execl (argv[1], argv[1], NULL);

}