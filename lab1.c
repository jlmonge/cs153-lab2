// #include <stdlib.h>
#include "types.h"
#include "stat.h"
#include "user.h"

void testExit(void);
void testWait(void);
void testWaitPid(void);
void testDebug(void);


int
main(int argc, char *argv[])
{	
	if (argc > 2 || argc < 2){
		printf(1,"Enter Exactly 2 arguments\n");
		exitWithStatus(2);
		return 0;
	}
	int input = atoi(argv[1]);

  	if (input == 1){
		testExit();
	}
	else if (input == 2){
		testWaitPid();
	}
	else if (input == 3){
		testWait();
	}
	else if (input == 4){
		testDebug();
	}

	exitWithStatus(0);
	return 0;
}

void testExit(void)
{
	printf(1,"Testing exitWithStatus()\n");
}

void testWait(void)
{
	printf(1,"Testing wait()\n");
}

void testWaitPid(void)
{
	printf(1,"Testing waitpid()\n");
}

void testDebug(void)
{
	printf(1,"Testing debug()\n");
}
