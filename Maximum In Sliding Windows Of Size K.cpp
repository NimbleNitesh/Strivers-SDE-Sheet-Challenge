#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    int n=nums.size();
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<k;i++)
    {
        while(!dq.empty()&&nums[dq.back()]<=nums[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        res.push_back(nums[dq.front()]);
        while(!dq.empty()&&dq.front()<=(i-k))
            dq.pop_front();
        while(!dq.empty()&&nums[dq.back()]<=nums[i])
            dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]);
    return res;
}