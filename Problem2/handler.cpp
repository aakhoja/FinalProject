#include <stdio.h>

#include <unistd.h>

#include <sys/types.h>
#include<stdio.h>
#include <cstdlib>
#include <time.h>
#include <gsl/gsl_rng.h>

bool isSuccess(int pert , int tri);

int ipd(int numTrials, bool isVerbose, int percent)

{
    pid_t pid2;
    printf("\n\n");

    if(isVerbose)
    {
        pid_t my_pid, parent_pid, child_pid;
        int status;

/* get and print my pid and my parent's pid. */

        my_pid = getpid();
        parent_pid = getppid();
        printf("\n Parent: my pid is %d\n\n", my_pid);
        printf("Parent: my parent's pid is %d\n\n", parent_pid);

/* print error message if fork() fails */
        if((child_pid = fork()) < 0 )
        {
            perror("fork failure");
            exit(1);
        }

/* fork() == 0 for child process */

        if(child_pid == 0)
        {  printf("\nChild: I am a new-born process!\n\n");
            my_pid = getpid();
            parent_pid = getppid();
            printf("Child: my pid is: %d\n\n", my_pid);
            printf("Child: my parent's pid is: %d\n\n", parent_pid);
            printf("Child: I will sleep 3 seconds and then execute - date - command \n\n");

            sleep(3);
            printf("Child: Now, I woke up and am executing date command \n\n");
            execl("/bin/date", "date", 0, 0);
            perror("execl() failure!\n\n");

            printf("This print is after execl() and should not have been executed if execl were successful! \n\n");

            _exit(1);
        }
/*
 * parent process
 */
        else
        {
            printf("\nParent: I created a child process.\n\n");
            printf("Parent: my child's pid is: %d\n\n", child_pid);
            system("ps -acefl | grep ercal");  printf("\n \n");
            wait(&status); /* can use wait(NULL) since exit status
                        from child is not used. */
            printf("\n Parent: my child is dead. I am going to read Nietzsche.\n \n ");
        }

        return 0;

    }

    bool succ = isSuccess(percent, numTrials);
    printf("\n The number generator trial resulted in %d", succ);


    return getpid();
}

bool isSuccess(int percent, int nTrails) {
    const gsl_rng_type * T;
    gsl_rng * q;
    long seed;
    
    gsl_rng_env_setup();
    T = gsl_rng_default;
    q = gsl_rng_alloc (T);
    
    // seed = time (NULL);
    //gsl_rng_set (q, seed);
    
    
    // get a random number from a uniform [0,1) distribution
    
    double u = gsl_rng_uniform (q);
    printf ("The y value is : %.5f\n", u);
    
    //return u;
    
    // at end of program must get rid of memory used by the generator
    gsl_rng_free (q);

    if (u <= percent) {
        return true;
    }
        else{
        return false;

    }


}
