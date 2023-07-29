int cutLogs(int k, int n)
{
    // Write your code here.
     // Write your code here.
    int dp[k+1][n+1];
    //dp[i][j]: i remaining axes and j remaining capacity
    for(int i=1;i<=n;i++)
        dp[0][i]=0;
    for(int i=0;i<=k;i++)
        dp[i][0]=0;
    for(int i=1;i<=k;i++)
    {
        int imp=0;
        for(int j=1;j<=n;j++)
        {
            //breaks at x-th floor  dp[i-1][x-1]+1
            //doesn't breaks dp[i][j-x]+1
            if(i==1)
            {
                dp[i][j]=j;
                continue;
            }
            // dp[i][j]=1e9;
            // for(int x=1;x<=j;x++){
                // int val=max(dp[i-1][x-1], dp[i][j-x]);
                // dp[i][j]=min(dp[i][j], val+1);
            // }
            int l=1, r=j;
            int ans=-1;
            int x=100;
            while(l<=r)
            {
                // x--;
                int mid=(l+r)/2;
                // cout << "mid=" << mid << " l=" << l << " r=" << r << endl;
                int v1=dp[i-1][mid-1];
                int v2=dp[i][j-mid];
                if(v1<=v2)
                {
                    l=mid+1;
                    ans=mid;
                }
                else
                {
                    r=mid-1;
                }
            }
            dp[i][j]=1+max(dp[i-1][ans-1], dp[i][j-ans]);
        }
    }
    // for(int i=1;i<=k;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    return dp[k][n];
}
