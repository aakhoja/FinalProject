#include "stdc++.h"

using namespace std;

/* Function to get the nth ugly number*/
unsigned getNthUglyNo(unsigned n)
{
    unsigned ugly[n]; // To store ugly numbers
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;
    
    ugly[0] = 1;
    for (int i=1; i<n; i++)
    {
        next_ugly_no = min(next_multiple_of_2,
                           min(next_multiple_of_3,
                               next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2 = i2+1;
            next_multiple_of_2 = ugly[i2]*2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3 = i3+1;
            next_multiple_of_3 = ugly[i3]*3;
        }
        if (next_ugly_no == next_multiple_of_5)
        {
            i5 = i5+1;
            next_multiple_of_5 = ugly[i5]*5;
        }
    } /*End of for loop (i=1; i<n; i++) */
    
    for (int i = 0; i <= sizeof(ugly)/sizeof(ugly[0]) - 1; i++)
        cout << ugly[i] << " " ;
    return next_ugly_no;
}

/* Driver program to test above functions */
int main()
{
    int i = 175;
    cout << "Please enter an integer value between 1 - 175: ";
    cin >> i;
    if(i <= 175){
    i = getNthUglyNo(i);
    cout << "\n";
    }
    else{
        cout << "Entered a number which was out of the range ";
    }
    return 0;
}
