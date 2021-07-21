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

int testExit(void)		//This function is used to test exitWithStatus(int status)					
{
	printf(1,"Testing exitWithStatus() for part A\n");
	//variables
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
		printf(1,"Child (pid:%d) has terminated \n", pid);
	}
	return 0;
}

int testWait(void)	//This funciton is used to test wait(int status) for part B
{
	printf(1,"Testing wait() for Part B\n");
	//variables
	int pid, status;
	char *argv[2] = {"./ls", NULL};

	pid = fork();

	if (pid < 0){
		printf(1, "ERROR: FORK");
		exitWithStatus(-1);
	}
	if (pid == 0){
		printf(1, "Hello from the child (pid:%d)\n", getpid());
		exec(argv[0], argv);
	}
	else{
		printf(1,"Hello from parent  of %d (pid:%d)\n",pid, getpid());
		sleep(3);		//Waits for text to print
		pid = wait(&status);
		printf(1,"Child status (%d)\n", &status); // Prints status of child 
		printf(1,"Child (pid:%d) has terminated \n", pid);
	}
	return 0;
}

int testWaitPid(void) //This function is used to test waitpid(pid,status,options)
{					  //for part C
	printf(1,"Testing waitpid() for PartC\n");
	//variables
	int pid, pid2 = 0, status, status2;
	int options = 0;

	char *argv[3] = {"./echo", "\"ECHO TEST\"", NULL};

	pid = fork();
	if (pid != 0){ //Creates second child
		pid2 = fork();
	}
	if (pid < 0 || pid2 < 0){
		printf(1, "ERROR: FORK");
		exitWithStatus(-1);
	}
	if (pid == 0 || pid2 == 0){
		printf(1, "Hello from the child (pid:%d)\n", getpid());
		sleep(5);
		exec(argv[0], argv);
	}
	else {
		printf(1,"Hello from parent  of %d and %d (pid:%d)\n",pid, pid2, getpid());
		sleep(10);		//Waits for text to print
		pid = waitpid(pid,&status,options);	//Waits for child 1 to finish
		pid2 = waitpid(pid2,&status2,options);	//Waits for child 2 to finish
		printf(1,"Child 1 status (%d)\n", &status); // Prints status of child 1
		printf(1,"Child 2 status (%d)\n", &status2); // Prints status of child 2
		printf(1,"Child (pid:%d) and Child (pid:%d) has terminated \n", pid, pid2);
	}
	
	return 0;
}

int testDebug(void) //This fucntion is used to test debug for part E
{
	printf(1,"Testing debug() for Part D\n");
	debug();
	return 0;
}
