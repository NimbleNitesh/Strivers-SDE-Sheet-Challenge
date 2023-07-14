#include <bits/stdc++.h> 
void solve(string &s, int l, int r, vector<string> &res)
{
    if(l==r)
        res.push_back(s);
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l], s[i]);
            solve(s, l+1, r, res);
            swap(s[l], s[i]);
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> res;
    int n=s.size();
    solve(s, 0, n-1, res);
    return res;
}