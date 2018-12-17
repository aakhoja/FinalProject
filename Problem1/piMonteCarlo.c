#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

//double yRand(long att);
int printPI(int att);

int main (void)
{
    long attempts;
    printf("Please input the attempts for this experiment: ");
    scanf("%ld", &attempts);
    
    return printPI(attempts);
}


int printPI(attempts){
    
    srand(time(NULL));
    double x, y, pi;
    long count = 0;
    // Throw 100000 darts randomly inside unit square
    for (int i = 0; i < attempts; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        printf("The x value is : %f\t",x);
        printf("the y value is : %f\n",y);
        if (pow(x, 2) + pow(y, 2) < 1) {
            count++;
        }
    }
    // count = number of "darts" that landed inside first quadrant that satisfies (0 <= x <= 1, 0 <= y <= 1)
    pi = (double) 4.0 * (count) / (attempts);
    // Since there are 4 quadrants to make up a circle, multiply by four. This gives approximation of pi.
    printf("# of trials= %d , estimate of pi is %g \n",attempts,pi);
    
    //system("pause");
    return 0;
    
    
    
}
