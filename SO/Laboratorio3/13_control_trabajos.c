#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i <= 30; i++) {
        printf("Trabajando... (%d/30)\n", i);
        sleep(1);
    }

    printf("Terminé.\n");
    return 0;
}

// Después de ejecutar el programa:
//
// Ctrl + Z
// jobs
// bg
// jobs
// fg
