#include <cstring>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    long long dp[n+1][value+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=value;j++)   
        {
            dp[i][j]=dp[i-1][j];
            int target=j-denominations[i-1];
            if(target>=0)
                dp[i][j]+=dp[i][target];
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=value;j++)
    //         cout << dp[i][j] << '\t';
    //     cout << '\n';
    // }
    return dp[n][value];
}