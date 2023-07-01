#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n=arr.size();
    vector<int> prefix_xor(n+1);
    prefix_xor[0]=0;
    for(int i=1;i<=n;i++)
        prefix_xor[i]=prefix_xor[i-1]^arr[i-1];
    int ans=0;
    map<int, int> full;
    full[0]=1;
    for(int i=1;i<=n;i++)
    {
        int req=prefix_xor[i]^x;
        if(full.find(req)!=full.end())
            ans+=full[req];
        full[prefix_xor[i]]++;
    }
    return ans;
}