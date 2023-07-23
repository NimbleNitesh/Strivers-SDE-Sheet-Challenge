#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    set<pair<int, pair<int, int>>> full;
    for(int i=0;i<k;i++)
    {
        full.insert({kArrays[i][0], {i, 0}});
    } 
    vector<int> res;
    while(!full.empty())
    {
        auto it=full.begin();
        pair<int, pair<int, int>> val=*it;
        full.erase(it);
        int allowed=kArrays[val.second.first].size();
        if(val.second.second+1<allowed)
        {
            full.insert({kArrays[val.second.first][val.second.second+1], {val.second.first, val.second.second+1}});
        }
        res.push_back(val.first);
    }
    return res;
}
