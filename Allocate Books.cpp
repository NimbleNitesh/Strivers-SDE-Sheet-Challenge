#include <bits/stdc++.h> 
bool check(long long mid, vector<int> &time, int &n, int &m)
{
	int ctr=1;
	long long cur_sum=0;
	for(int i=0;i<m;i++)
	{
		if(time[i]>mid)
			return false;
		if((cur_sum+time[i])<=mid)
			cur_sum+=time[i];
		else
		{
			cur_sum=time[i];
			ctr++;
		}
	}
	return (ctr<=n);
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long l=0, r=1e14;
	long long ans=-1;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid, time, n, m))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return ans;
}