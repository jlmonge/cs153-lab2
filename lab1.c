#include "types.h"
#include "stat.h"
#include "user.h"

int testExit(void);
int testWait(void);
int testWaitPid(void);
int testDebug(void);


int
main(int argc, char *argv[])
{	
	if (argc > 2 || argc < 2){
		printf(1,"Enter Exactly 2 arguments\n");
		return 0;
	}
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
	exit();
	return 0;
}

int testExit(void)
{
	printf(1,"Testing exitWithStatus() for part A\n");
	int pid;
	pid = fork();
	if (pid == -1){
		printf(1, "ERROR: FORK");
		exitWithStatus(-1);
	}
	if (pid == 0){
		printf(1, "Hello from the child pid (%d)(%d)\n", pid, getpid());
		exitWithStatus(0);
	}
	else{
		printf(1, "Hello from parent (%d)\n",pid);
		exitWithStatus(0);
	}
	return 0;
}

int testWait(void)
{
	printf(1,"Testing wait() for Part B\n");
	int pid, status;
	pid = fork();
	if (pid == 0){
		printf(1,"Hello from child with pid(%d)\n", pid);
		printf(1,"Childs parent pid (%d)\n", getpid());
	}
	else{
		printf(1,"Hello form parent\n");
		wait(&status);
		printf(1,"Child has terminated was pid (%d)\n", pid);
		printf(1,"Parent pid (%d)\n",getpid());
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
	if (pid ==0){
		printf(1,"Hello from child pid (%d)\n", pid);
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
