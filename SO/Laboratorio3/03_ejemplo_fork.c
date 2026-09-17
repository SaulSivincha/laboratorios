#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample()
{
    if (fork() == 0)
        printf("Hola desde el hijo!\n");
    else
        printf("Hola desde el padre!\n");
}

int main()
{
    forkexample();
    return 0;
}
