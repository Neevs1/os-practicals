#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void main(){
	pid_t pid;
	pid = fork();
	if(pid>0){
		sleep(30);
		printf("Parent process ID id %d\n",getpid());
		printf("In parent process");
	}
	else if(pid==0){
	 printf("Child process ID is %d\n Parent ID is %d\n",getpid(),getppid());
	 printf("In child process");
	 printf("Child terminated");
	
	}


}

/*
Child process ID is 6474
 Parent ID is 6473
In child processChild terminatedParent process ID id 6473
In parent process%     

ps -eo pid,ppid,stat  
    PID    PPID STAT
      1       0 Ss
      2       0 S
      3       2 I<
      .
      .
      .
    6473    5201 S+
    6474    6473 Z+
    6475    5314 R+
*/
