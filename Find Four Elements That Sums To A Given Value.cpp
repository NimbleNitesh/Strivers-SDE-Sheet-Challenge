#include <bits/stdc++.h>
bool isCommon(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    if(a.second.first==b.second.first||a.second.first==b.second.second)
        return 0;
    if(a.second.second==b.second.second||a.second.second==b.second.second)
        return 0;
    return 1;
}
string fourSum(vector<int> a, int target, int n) {
    // Write your code here.
    vector<pair<int, pair<int, int>>> full;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            full.push_back({a[i]+a[j], {i, j}});
    sort(full.begin(), full.end());
    int l=0;
    int r=full.size()-1;
    while(l<r)
    {
        int cur=full[l].first+full[r].first;
        if(cur==target&&isCommon(full[l], full[r]))
        {
            return "Yes";
        }
        if(cur<target)
            l++;
        else
            r--;
        
    }
    return "No";
}
