#include <bits/stdc++.h>
struct item{
	int val, l, r;
}; 
bool customsort(item &a, item &b)
{
	if(a.val==b.val)
		return a.l>b.l;
	return a.val>b.val;
}
struct FenwickTree
{
	int n;
	vector<int> bit;
	FenwickTree(int n)
	{
		this->n=n;
		bit.assign(n, 0);
	}	
	void set(int i, int delta)
	{
		while(i<n)
		{
			bit[i]+=delta;
			i=i|(i+1);
		}
	}
	int query(int r)
	{
		int sum=0;
		while(r>=0)
		{
			sum+=bit[r];
			r=(r&(r+1));
			r--;
		}
		return sum;
	}
};
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	vector<item> full(2*n);
	for(int i=0;i<n;i++)
		full[i]={arr[i], -1, i};
	int pos=n;
	for(int i=n-1;i>=0;i--)
	{
		full[pos]={2*arr[i], 0, i};
		pos++;
	}
	// for(int i=0;i<2*n;i++)
	// 	cout << "org " << full[i].val << ' ' << full[i].l << endl;
	sort(full.begin(), full.end(), customsort);
	// for(int i=0;i<2*n;i++)
	// 	cout << "exe " << full[i].val << ' ' << full[i].l << endl;
	FenwickTree ft(n);
	int ans=0;
	for(int i=0;i<2*n;i++)
	{
		if(full[i].l==-1)
		{
			ft.set(full[i].r, 1);
			// cout << "set " << full[i].r << " val=" << full[i].val << endl;
		}
		else
		{
			// cout << full[i].val << ' ' << full[i].l << ' ' << full[i].r << endl;
			int val=ft.query(full[i].r);
			// cout << val << endl;
			ans+=val;
		}
		
	}
	return ans;
	// return 0;
}