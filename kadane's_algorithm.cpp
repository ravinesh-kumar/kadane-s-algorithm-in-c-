/*
Explanation: 
The simple idea of Kadane’s algorithm is to look for all positive contiguous segments of the 
array (max_ending_here is used for this). And keep track of the maximum sum contiguous segment 
among all positive segments (max_so_far is used for this). Each time we get a positive-sum compare 
it with max_so_far and update max_so_far if it is greater than max_so_far 


Lets take the example:
    {-2, -3, 4, -1, -2, 1, 5, -3}

    max_so_far = INT_MIN
    max_ending_here = 0

    for i=0,  a[0] =  -2
    max_ending_here = max_ending_here + (-2)
    Set max_ending_here = 0 because max_ending_here < 0
    and set max_so_far = -2

    for i=1,  a[1] =  -3
    max_ending_here = max_ending_here + (-3)
    Since max_ending_here = -3 and max_so_far = -2, max_so_far will remain -2
    Set max_ending_here = 0 because max_ending_here < 0
      
    
    for i=2,  a[2] =  4
    max_ending_here = max_ending_here + (4)
    max_ending_here = 4
    max_so_far is updated to 4 because max_ending_here greater 
    than max_so_far which was -2 till now

    for i=3,  a[3] =  -1
    max_ending_here = max_ending_here + (-1)
    max_ending_here = 3

    for i=4,  a[4] =  -2
    max_ending_here = max_ending_here + (-2)
    max_ending_here = 1

    for i=5,  a[5] =  1
    max_ending_here = max_ending_here + (1)
    max_ending_here = 2

    for i=6,  a[6] =  5
    max_ending_here = max_ending_here + (5)
    max_ending_here = 7
    max_so_far is updated to 7 because max_ending_here is 
    greater than max_so_far

    for i=7,  a[7] =  -3
    max_ending_here = max
 */

#include<cstdlib>
#include<cstdio>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
int maxSumArray(int arr[])
{
    int maxsum=0;
    int cursum=0;
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0;i<n+1;i++)
    {
        cursum = cursum+arr[i];

        if(cursum>maxsum)
        {
            maxsum = cursum;
        }
        if(cursum<0)
        {
            return (maxsum);
        
        }
    }
    return(maxsum);
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSumArray(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}

