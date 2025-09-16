#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* func(void* arg) {
    printf("Evil program that terminates after you put enter even number\n");
    int x;
    scanf("%d",&x);
    if(x%2==0){
    	pthread_exit(NULL);
    }
    printf("Thank god you didn't enter even number");
    
    return NULL;
}



int main() {
    pthread_t thread1;
    
    pthread_create(&thread1, NULL, func, NULL);
   
    
    pthread_join(thread1, NULL);
    return 0;
}
