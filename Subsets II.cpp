#include <bits/stdc++.h> 
void rec(int ind, int &n, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr)
{
    ans.push_back(temp);
    // cout << "ind=" << ind << endl;
    for(int i=ind;i<n;i++)
    {
        if(i!=ind&&arr[i]==arr[i-1])
            continue;
        temp.push_back(arr[i]);
        rec(i+1, n, temp, ans, arr);
        temp.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> temp;
    rec(0, n, temp, ans, arr);

    return ans;
}