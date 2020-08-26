#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int pid = fork();
	// Parent process
	if (pid > 0)
		sleep(20);

	// Child process
	else
	{
		exit(0);
	}

	return 0;

}
