#include <signal.h>
#include <stdio.h>

void alrmhandler(int) {
    static int count = 0;
    printf("Timer expired: %d!\n", ++count);
}

int main() {
    signal(SIGALRM, alrmhandler);
    for (;;);
}
