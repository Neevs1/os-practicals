#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    int x=0;
    pid_t i;
    i=fork();
    if(i==0){
    	while(x<10){
    		printf("Child process pid = %d ppid= %d\n",getpid(),getppid());
    		sleep(3);
    		x+=1;
    }    
    
    }else{
     printf("Parent is ☠️\n");
    }
	return 0;
}

/*
 Output
 Parent is ☠️
Child process pid = 9338 ppid= 9337
Child process pid = 9338 ppid= 1371                  
Child process pid = 9338 ppid= 1371
Child process pid = 9338 ppid= 1371
Child process pid = 9338 ppid= 1371
Child process pid = 9338 ppid= 1371
Child process pid = 9338 ppid= 1371
Child process pid = 9338 ppid= 1371
Child process pid = 9338 ppid= 1371
Child process pid = 9338 ppid= 1371
*/
