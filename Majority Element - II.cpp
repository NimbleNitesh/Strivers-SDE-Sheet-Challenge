#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    int n=arr.size();
    int res=n/3;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        while(j<n&&arr[j]==arr[i])
            j++;
        int len=j-i;
        if(len>res)
            ans.push_back(arr[i]);
        i=j-1;
    }
    return ans;
}