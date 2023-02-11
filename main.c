#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void alrmhandler(int) {
    static int count = 0;
    printf("Timer expired: %d!\n", ++count);
}

int main() {
    signal(SIGALRM, alrmhandler);

    pid_t pid = getpid();
    if (fork() == 0) {
        char arg[16];
        sprintf(arg, "%d", pid);
        execl("timer", "timer", arg, NULL);
    }

    for (;;);
}
