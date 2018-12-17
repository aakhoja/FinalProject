#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mach/machine.h>
#include <sys/types.h>
#include <gsl/gsl_rng.h>
#include "handler.cpp"

int ipd(int n);

int main(int argc,char* argv[]) {

    int percentage = 0;

    int ab = 0;

    boolean_t verbose = false;

    int trials = 0;

    int cord = 0;// no c or d = 0, c = 1, d = 2

//flags and a/b value holders

    int getoptvalue = 0;

   // char **arg[] = ("./handler",argv[2],argv[3],NULL);

    printf("starting getopt\n");

    while((getoptvalue = getopt(argc,argv,"p:vt::")) != -1){

        printf("inside getopt\n");

        switch(getoptvalue){

            case 'p':{
                        percentage = atoi(optarg);//takes int value following 'a' for storage in av?
                        printf("The percentage entered is : %i", percentage);
                        char txt[16];
                        //sprintf(txt, "%d" , percentage);
                       // execv("./handler ",arg);

               // int test = testfile.c.pid();

                }break;

            case 'v':{

                    verbose = true;
                    printf("The verbose value entered is : %i", verbose);

                }break;

            case 't':{
                    int PID = 0;
                    trials = atoi(optarg);//takes int value following 'a' for storage in av?
                    PID  = ipd(trials, verbose , percentage);
                    printf("The trials entered is : %i\n", trials);
                    printf("The PID returned is : %i\n", PID);
                }break;

            case '?':{


                }break;

            default: break;

        }

        printf("done.\n");

    }
    return 0;
}
