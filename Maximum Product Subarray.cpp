#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	vector<int> pos={-1};
	for(int i=0;i<n;i++)
		if(arr[i]==0)
			pos.push_back(i);
	pos.push_back(n);
	int m=pos.size();
	int ans=(m>2)?0:INT_MIN;
	for(int i=1;i<m;i++)
	{
		int first_neg=1, last_neg=1;
		int cur=1;
		for(int j=pos[i-1]+1;j<pos[i];j++)
		{
			cur*=arr[j];
			if(first_neg>0)
				first_neg*=arr[j];
		}
		for(int j=pos[i]-1;j>=pos[i-1]+1;j--)
		{
			if(last_neg>0)
				last_neg*=arr[j];
		}
		int len=pos[i]-pos[i-1]-1;
		if(len==0)
			continue;
		if(cur<0&&len>1)
		{
			cur/=(max(first_neg, last_neg));
		}
		ans=max(ans, cur);
	}
	return ans;
}
