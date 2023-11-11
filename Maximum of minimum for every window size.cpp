#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> res(n);
    vector<pair<int, int>> range(n);
    for(int i=0;i<n;i++)
        range[i].first=a[i];
    stack<int> full;
    //nect smaller element
    //a[i] kiska next smaller element hoga??
    full.push(0);
    for(int i=1;i<n;i++)
    {
        if(full.empty())
        {
            full.push(i);
            continue;
        }
        while(!full.empty()&&a[full.top()]>a[i])
        {
            range[full.top()].second=i;
            full.pop();
        }
        full.push(i);
    }
    while(!full.empty())
    {
        range[full.top()].second=n;
        full.pop();
    }
    // for(int i=0;i<n;i++)
    //     cout << range[i].first << ' ' << range[i].second << '\n';
    // cout << '\n';
    //prev smaller element
    full.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        if(full.empty())
        {
            full.push(i);
            continue;
        }
        while(!full.empty()&&a[full.top()]>a[i])
        {
            // cout << "exe  " << a[full.top()] << ' ' << i << endl; 
            range[full.top()].second=range[full.top()].second-i-1;
            full.pop();
        }
        full.push(i);
    }
    while(!full.empty())
    {
        // range[full.top]
        full.pop();
    }
    // // return res;
    // for(int i=0;i<n;i++)
    //     cout << range[i].first << ' ' << range[i].second << '\n';
    sort(range.begin(), range.end());
    int cur=0;
    for(int i=n-1;i>=0;i--)
    {
        int rr=range[i].second;
        if(rr<=cur)
        {
            continue;
        }
        for(int j=cur;j<rr;j++)
            res[j]=range[i].first;
        cur=rr;
    }
    return res;
}