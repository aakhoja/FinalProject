#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

double getxRand(int att)
double getyRand(int att)

double getxRand(long attempts){
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
    
    return u;
    
    // at end of program must get rid of memory used by the generator
    gsl_rng_free (q);
    
}


double getyRand(long attempts){
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
    
    return u;
    
    // at end of program must get rid of memory used by the generator
    gsl_rng_free (q);
    
}

