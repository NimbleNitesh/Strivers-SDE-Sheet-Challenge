#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n=arr.size();
  map<int, int> full;
  full[0]=-1;
  int cur=0, ans=0;
  for(int i=0;i<n;i++)
  {
    cur+=arr[i];
    if(full.find(cur)!=full.end())
    {
      ans=max(ans, i-full[cur]);
    }
    else
    {
      full[cur]=i;
    }
  }
  return ans;

}