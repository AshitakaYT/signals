#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void    handler(int num)
{
    write(STDOUT_FILENO, "I wont die !\n", 13);
}

void	segfault(int num)
{
	write(STDOUT_FILENO, "Segfault noob!\n", 15);

}


int main()
{
    int *i = NULL;

    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGSEGV, segfault);
    *i = 45;
    while (1)
    {
        printf("wasting your signals. %d\n", getpid());
        sleep(1);
    }
    return (0);
}   