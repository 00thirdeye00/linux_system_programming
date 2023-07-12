#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void alarm_handler(int signum){
	printf("Alarm delivered signum is %d\n", signum);
	// system("/bin/ls");	
	exit(0);
}


int main(){
	alarm(5);
	signal(SIGALRM, alarm_handler);

	for(;;)
		sleep(1);

	return 0;
}
















