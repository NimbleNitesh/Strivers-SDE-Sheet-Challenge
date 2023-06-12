#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> res(n);
  if(n==1)
  {
    res[0].push_back(1);
    return res;
  }
  vector<long long int> ttt(1);
  ttt[0]=1;
  res[0]=ttt;
  for(int i=1;i<n;i++)
  {
    vector<long long int> temp(i+1);
    temp[0]=1;
    temp[i]=1;
    for(int j=1;j<i;j++)
      temp[j]=res[i-1][j-1]+res[i-1][j];
    res[i]=(temp);
  }
  // for(auto i: res)
  // {
  //   for(auto j: i)
  //     cout << j << ' ';
  //   cout << '\n';
  // }
  return res;
}
