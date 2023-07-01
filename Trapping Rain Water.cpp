#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        while(j<n&&arr[j]<arr[i])
            j++;
        if(j<n)
        {
            int len=j-i-1;
            ans+=(len*arr[i]);
            for(int k=i+1;k<j;k++)
                ans-=arr[k];
            // cout << len*arr[i] << endl;
        }
        i=j-1;   
    }
    for(int i=n-1;i>=0;i--)
    {
        int j=i-1;
        while(j>=0&&arr[j]<=arr[i])
            j--;
        if(j>=0)
        {
            int len=i-j-1;
            ans+=(len*arr[i]);
            for(int k=j+1;k<i;k++)
                ans-=arr[k];
            // cout << len*arr[i] << endl;
        }
        i=j+1;
    }
    return ans;
}