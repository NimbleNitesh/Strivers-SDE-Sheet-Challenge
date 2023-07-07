#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n=input.size();
    int pos[26], dp[n+1];
    memset(pos, -1, sizeof(pos));
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int index=input[i-1]-'a';
        int len=i-pos[index];
        if(len>dp[i-1]+1)
        {
            dp[i]=dp[i-1]+1;
            if(i>1&&input[i-2]==input[i-1])
                dp[i]=0;
        }
        else
            dp[i]=len;
        pos[index]=i;
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        ans=max(ans, dp[i]);
    return ans;
}