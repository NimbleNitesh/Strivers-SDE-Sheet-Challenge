#include <bits/stdc++.h>
bool customsort(vector<int> &a, vector<int> &b)
{
   if(a[0]==b[0])
      return a[1]<b[1];
   return a[0]<b[0];
}
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   map<int, int> full;
   for(auto &i: arr)
      full[i]++;
   vector<vector<int>> res;
   for(int i=0;i<arr.size();i++)
   {
      int other=s-arr[i];
      if(other>arr[i]&&(full.find(other)!=full.end()))
      {
         int m=full[other];
         for(int j=0;j<m;j++)
            res.push_back({arr[i], other});
      }
   }
   if(s%2==0)
   {
      int m=full[s/2]*(full[s/2]-1)/2;
      for(int j=0;j<m;j++)
         res.push_back({s/2, s/2});
   }
   sort(res.begin(), res.end(), customsort);
   return res;
}