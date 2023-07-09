#include <cstring>
string longestPalinSubstring(string str)
{
    // Write your code here.
    int n=str.size();
    if(n<=1)
        return str;
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    int maxLength=1, maxIndex=0;
    for(int i=0;i<n;i++)
        dp[i][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<n;i++)
        {
            int j=i+len-1;
            if(j>=n)
                break;
            if(str[i]!=str[j])
                continue;
            if(len==2)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i+1][j-1];
            if(len>maxLength&&dp[i][j])
            {
                maxIndex=i;
                maxLength=len;
            }
        }
    }
    string res;
    for(int i=maxIndex;i<(maxIndex+maxLength);i++)
        res.push_back(str[i]);
    return res;
}