#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(), arr.end());
	set<vector<int>> full;
	vector<vector<int>> res;
	for(int i=0;i<n;i++)
	{
		int target=K-arr[i];
		if(arr[i]>K/3)
			break;
		int l=0, r=n-1;
		while(l<r)
		{
			while(l==i)
				l++;
			while(r==i)
				r--;
			if(l>=r)
				break;
			if(arr[l]+arr[r]==target)
			{
				vector<int> cur;
				cur.push_back(arr[l]);
				cur.push_back(arr[r]);
				cur.push_back(arr[i]);
				sort(cur.begin(), cur.end());
				full.insert(cur);
				int cur_l=arr[l];
				while(arr[l]==cur_l)
					l++;
				int cur_r=arr[r];
				while(arr[r]==cur_r)
					r--;
			}
			else if(arr[l]+arr[r]<target)
				l++;
			else
				r--;
		}
	}
	for(auto i: full)
		res.push_back(i);
	return res;
}