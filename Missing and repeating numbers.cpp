#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int freq[n];
	memset(freq, 0, sizeof(freq));
	int m, r;
	for(int i=0;i<n;i++)
	{
		freq[arr[i]-1]++;
		if(freq[arr[i]-1]>1)
			r=arr[i];
	}
	for(int i=0;i<n;i++)
		if(freq[i]==0)
		{
			m=i+1;
			break;
		}
	return make_pair(m, r);
}
