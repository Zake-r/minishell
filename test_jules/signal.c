


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handle_sigint(int sig)
{
    printf("\nprogram finished\n");
    exit(1);
}

void handle_segv(int sig)
{
	perror("Segmentation fault\n");
    exit(1);
}

int main(void)
{
    signal(SIGINT, handle_sigint);
    signal(SIGSEGV, handle_segv);
    while (1) {}


}