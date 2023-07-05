#include <vector>
#include <algorithm>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    const int inf=1e9;
    vector<int> dp(n+1, inf);
    dp[0]=-inf;
    //dp[i]: minimum element at which LIS of length i ends
    for(int i=0;i<n;i++)
    {
        auto it=upper_bound(dp.begin(), dp.end(), arr[i]);
        int pos=it-dp.begin();
        if(dp[pos-1]<arr[i])
        {
            dp[pos]=min(dp[pos], arr[i]);
        }
    }
    for(int i=n;i>=0;i--)
        if(dp[i]!=inf)
            return i;
}
