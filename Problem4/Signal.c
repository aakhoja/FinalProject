#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void childHandler(int);
void parentHandler(int);

int main(void){
    
    struct sigaction sigact;
    
    sigact.sa_handler = childHandler;
    if(sigaction(SIGINT, &sigact,NULL) < 0){
        perror("Error" );
        exit(1);
    }
    
    sigact.sa_handler = parentHandler;
    if(sigaction(SIGINT, &sigact,NULL) < 0){
        perror("Error" );
        exit(1);
    }
    
    pid_t pid;
    if((pid = fork()) < 0){
        perror("Fork process erorr " );
        exit(1);
    }
    
    else if(pid == 0)
    {
        while(1){
            printf("Child has been created as its waiting \n" );
            sleep(1);
        }
    }
    
    else {
        sleep(1);
        printf("Parent sending signal \n");
        kill(pid,SIGINT);
        sleep(3);
        printf("\nParent sending quit signal " );
        kill(pid,SIGQUIT);
        sleep(3);
    }
    
    
}

void childHandler(int sig){
    signal(SIGINT,childHandler);
    printf("Signal recieved by child \n");
}

void parentHandler(int sig){
    printf("Parent will exit now\n");
    exit(0);
}
