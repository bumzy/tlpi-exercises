/* Exercise 25-1: when child process exit(-1), father process accept what exit status */
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tlpi_hdr.h"

int main(int argc, char const *argv[])
{
	int status;
	switch(fork()){
		case -1:
			errExit("fork");
		case 0:
			exit(-1);
			break;
		default:
			wait(&status);
			printf("%d\n", WEXITSTATUS(status));
	}
	exit(EXIT_SUCCESS);
}