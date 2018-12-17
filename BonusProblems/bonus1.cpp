#include <stdio.h>
#include <math.h>


int x;
double f;
#define PI 3.14159265

double log_fact (int n);




int main(void)
{
    
    printf("Enter an integer :");
    scanf("%d" , &x);
    
    for(int i = 1;i<=x;i++)
    {
    double stirling_res;
    double exact_res;
    
     exact_res = log_fact(i);
     stirling_res = 0.5*log(2*PI) + (i + 0.5)*log(i) - i;
    
    double error = exact_res - stirling_res;
    int perror = error * 100;
      printf ("ln(%d!) = %.6lf\t", i, exact_res);
    printf ("Stirling's apporximation is %.6lf\t", stirling_res);
    printf ("Error is %.6lf\t", error);
    printf ("Percent error is %.2d", perror);
    printf ("%\n");
    }
    
    return 0;
}

double log_fact (int n)
{
    if (n <= 1)
    /* Since 0! = 1! = 1, we can simple return ln(1) = 0: */
        return (0);
    
    /* Use the equality: ln(n!) = ln((n-1)!) + ln(n) */
    return (log_fact(n - 1) + log (n));
}
