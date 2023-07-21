#include <bits/stdc++.h> 
bool isPresent(vector<string> &arr, string &s)
{
    for(auto i: arr)
        if(i==s)
            return true;
    return false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    n=target.size();
    bool dp[n];//dp[i] indicates whether substring target[0...i] is makable or not.
    memset(dp, 0, sizeof(dp));
    vector<int> matched_indices={-1};
    for(int i=0;i<n;i++)
    {
        int m=matched_indices.size();
        for(int j=m-1;j>=0;j--)
        {
            string str=target.substr(matched_indices[j]+1, i-matched_indices[j]);
            if(isPresent(arr, str))
            {
                // cout << i << ' ' << str << endl;
                matched_indices.push_back(i);
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n-1];
}