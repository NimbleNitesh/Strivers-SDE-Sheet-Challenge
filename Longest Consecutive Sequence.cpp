#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> full;
    for(auto &i: arr)
        full.insert(i);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        auto it=full.find(arr[i]-1);
        if(it==full.end())
        {
            int j=arr[i];
            while(full.find(j)!=full.end())
                j++;
            ans=max(ans, j-arr[i]);
        }
    }
    return ans;
}