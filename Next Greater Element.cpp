#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> res(n, -1);
    stack<int> full;
    full.push(0);
    for(int i=1;i<n;i++)
    {
        while(!full.empty())
        {
            int ind=full.top();
            if(arr[ind]<arr[i])
            {
                res[ind]=arr[i];
                full.pop();
            }
            else
                break;
        }
        full.push(i);
    }
    return res;
}