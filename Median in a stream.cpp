#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	// Write your code here 
	vector<int> res;
	multiset<int> r;
	multiset<int, greater<int>> l;
	for(int i=0;i<n;i++)
	{
		int l_size=l.size();
		int r_size=r.size();
		if(l_size==r_size)
		{
			if(l.empty())
			{
				res.push_back(arr[i]);
				l.insert(arr[i]);
				continue;
			}
			//l me insert ya r me insert
			int val=(*r.begin());
			if(arr[i]<=val)
			{
				l.insert(arr[i]);
				res.push_back(*l.begin());
				continue;
			}
			r.insert(arr[i]);
			res.push_back(*r.begin());
		}
		else if(l_size>r_size)
		{
			// if((l_size+r_size)&1==0)
			// {
			// 	cout << "ERROR\n";
			// 	break;
			// }
			// if(r.empty())
			// {
				l.insert(arr[i]);
				while(l_size>r_size)
				{
					r.insert(*l.begin());
					l.erase(l.begin());
					l_size--;
					r_size++;
				}
				int vv=(*l.begin())+(*r.begin());
				vv/=2;
				res.push_back(vv);
			// }
		}
		else
		{
			r.insert(arr[i]);
			while(r_size>l_size)
			{
				l.insert(*r.begin());
				r.erase(r.begin());
				l_size++;
				r_size--;
			}
			int vv=(*l.begin())+(*r.begin());
				vv/=2;
				res.push_back(vv);
		}
	}
	return res;
}
