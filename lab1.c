#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

int testExit(void);
int testWait(void);
int testWaitPid(void);
int testDebug(void);


int
main(int argc, char *argv[])
{	
	if (argc != 2){
		printf(1,"Enter exactly 2 arguments\n");
	}
	else{
		int input = atoi(argv[1]);

  		if (input == 1){
			testExit();
		}
		else if (input == 2){
			testWait();
		} 
		else if (input == 3){
			testWaitPid();
		}
		else if (input == 4){
			testDebug();
		}
	}
	
	exit();
	return 0;
}

int testExit(void)
{
	printf(1,"Testing exitWithStatus() for part A\n");
	int pid;
	pid = fork();
	if (pid < 0){
		printf(1, "ERROR: FORK");
		exitWithStatus(-1);
	}
	else if (pid == 0){
		printf(1, "Hello from the child (pid:%d)\n", getpid());
		exitWithStatus(0);
	}
	else{
		printf(1, "Hello from parent of %d (pid:%d)\n", pid, getpid());
		pid = wait(NULL);
		printf(1, "Child (pid:%d) has exited", pid);
	}
	return 0;
}

int testWait(void)
{
	printf(1,"Testing wait() for Part B\n");
	int pid, status;
	pid = fork();
	if (pid == 0){
		printf(1,"Hello from child with pid %d\n", getpid());
		//printf(1,"Child's parent pid (%d)\n", getpid()); // prints child pid
	}
	else{
		printf(1,"Hello from parent (pid:%d)\n", getpid());
		wait(&status);
		printf(1,"Child (pid:%d) has terminated \n", pid);
		printf(1,"Parent pid (%d)\n", getpid());
	}
	printf(1,"End\n");
	return 0;
}

int testWaitPid(void)
{
	printf(1,"Testing waitpid() for PartC\n");
	
	int pid, status;

	printf(1,"Parent: %d\n",getpid());
	pid = fork();
	if (pid == 0){
		printf(1,"Hello from child pid (%d)\n", getpid());
		sleep(2);
		exitWithStatus(0);
	}
	waitpid(pid,&status,0);

	printf(1,"Hello from parent pid (%d)\n", getpid());
	
	return 0;
}

int testDebug(void)
{
	printf(1,"Testing debug() for Part D\n");
	debug();
	return 0;
}
