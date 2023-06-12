#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long dp[n];
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            dp[i]=1ll*arr[i];
        else
            dp[i]=max(dp[i-1]+arr[i], 1ll*arr[i]);
        ans=max(ans, dp[i]);
    }
    return ans;
}