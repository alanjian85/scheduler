#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define QUANTUM 1

int main(int argc, char** argv) {
    pid_t pid = atoi(argv[1]);
    for (;;) {
        sleep(QUANTUM);
        kill(pid, SIGALRM);
    }
}
