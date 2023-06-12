#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int minimum=prices[0];
    int res=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int cur=prices[i]-minimum;
        res=max(res, cur);
        minimum=min(minimum, prices[i]);
    }
    return res;
}