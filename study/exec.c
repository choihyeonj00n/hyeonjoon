#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
		char *argv[3];
		argv[0] = "echo";
		argv[1] = "hello";
		argv[2] = 0;
		execvp("/bin/echo", argv);
		printf("exec error\n");
		return 0;
}
