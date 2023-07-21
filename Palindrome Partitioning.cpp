#include <bits/stdc++.h> 
void allPartition(int index, int &n, vector<int> &ind, vector<vector<int>> &partitions)
{
    // cout << index << '\n';
    //ind[i] contains index of ending a new substring
    if(index==n){
        ind.push_back(n);
        partitions.push_back(ind);
        ind.pop_back();
        return;
    }
    // cout << "ind=" << index << '\n';
    // return;
    int maxLength=n-index;
    ind.push_back(index);
    for(int i=1;i<=maxLength;i++)
    {
        allPartition(index+i, n, ind, partitions);
    }
    ind.pop_back();
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    if(s.empty())
        return {{}};
    vector<vector<int>> partitions;
    int n=s.size();
    vector<int> ind;
    allPartition(0, n, ind, partitions);
    // for(auto i: partitions)
    // {
    //     for(auto j: i)
    //         cout << j << ' ';
    //     cout << '\n';
    // }
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<n;i++)
        {
            int j=i+len-1;
            if(j>=n)
                break;
            if(len==2)
            {
                if(s[i]==s[j])
                    dp[i][j]=1;
            }
            else
            {
                if(s[i]==s[j])
                    dp[i][j]|=dp[i+1][j-1];
            }
        }
    }
    int m=partitions.size();
    vector<vector<string>> ans;
    for(int i=0;i<m;i++)
    {
        int q=partitions[i].size();
        assert(q>1);
        bool res=1;
        for(int j=1;j<q;j++)
        {
            res&=dp[partitions[i][j-1]][partitions[i][j]-1];
        }
        if(res)
        {
            vector<string> possible;
            for(int j=1;j<q;j++)
            {
                possible.push_back(s.substr(partitions[i][j-1], partitions[i][j]-partitions[i][j-1]));
            }
            ans.push_back(possible);
        }
    }
    return ans;
}