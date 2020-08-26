// C++ program to demonstrate creating processes using fork()
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fc = fork();
    int sc = fork();

    if (fc > 0 && sc > 0) {
        printf("Parent\n");
        printf("%d %d \n", fc, sc);
        printf("ID: %d \n", getpid());
    }
    else if (fc == 0 && sc > 0)
    {
        printf("First child\n");
        printf("%d %d \n", fc, sc);
        printf("ID: %d \n", getpid());
    }
    else if (fc > 0 && sc == 0)
    {
        printf("Second child\n");
        printf("%d %d \n", fc, sc);
        printf("ID: %d \n", getpid());
    }
    else {
        printf("third child\n");
        printf("%d %d \n", fc, sc);
        printf("ID: %d \n", getpid());
    }
    return 0;
}
