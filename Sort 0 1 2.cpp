#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int cnt[2];
   memset(cnt, 0, sizeof(2));
   for(int i=0;i<n;i++)
      if(arr[i]!=2)
         cnt[arr[i]]++;
   for(int i=0;i<n;i++)
   {
      if(cnt[0])
      {
         cnt[0]--;
         arr[i]=0;
         continue;
      }
      if(cnt[1])
      {
         cnt[1]--;
         arr[i]=1;
         continue;
      }
      arr[i]=2;
   }

}