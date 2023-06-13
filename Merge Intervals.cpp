#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
bool isIntersecting(pair<int, int> &a, pair<int, int> &b)
{
    if(a.first>b.second || b.first>a.second)
        return 0;
    return 1;
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int n=intervals.size();
    vector<pair<int, int>> a(n);
    vector<vector<int>> res;
    for(int i=0;i<n;i++)
    {
        int l=min(intervals[i][0], intervals[i][1]);
        int r=max(intervals[i][0], intervals[i][1]);
        a[i]=make_pair(l, r);
    }
    // for(auto i: a)
    //     cout << i.first << ' ' << i.second << endl;
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++)
    {
        pair<int, int> cur=a[i];
        int j=i+1;
        while(j<n&&isIntersecting(cur, a[j]))
        {
            cur.second=max(cur.second, a[j].second);
            j++;
        }
        vector<int> temp(2);
        temp[0]=cur.first;
        temp[1]=cur.second;
        res.push_back(temp);
        i=j-1;
    }
    // cout << "hi\n";
    return res;
}
