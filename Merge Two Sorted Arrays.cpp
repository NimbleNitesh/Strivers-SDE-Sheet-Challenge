#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	vector<int> res(n+m, -1);
	int l1=0, l2=0, ptr=0;
	while(true)
	{
		if(l1<m&&l2<n)
		{
			// cout << "1\n";
			if(arr1[l1]==0)
			{
				res[ptr]=arr2[l2];
				l2++;
				ptr++;
			}
			else if(arr1[l1]<arr2[l2])
			{
				res[ptr]=arr1[l1];
				l1++;
				ptr++;
			}
			else
			{
				res[ptr]=arr2[l2];
				l2++;
				ptr++;
			}
		}
		else if(l1==m&&l2<n)
		{
			// cout << "2\n";
			res[ptr]=arr2[l2];
			l2++;
			ptr++;
		}
		else if(l2==n)
		{
			// cout << "3\n";
			if(l1==m)
				break;
			if(arr1[l1]==0)
				break;
			res[ptr]=arr1[l1];
			l1++;
			ptr++;
		}
	}
	// for(int i=0;i<m;i++)
	// 	cout << res[i] << ' ';
	// cout << '\n' << "hello\n";
	return res;
}