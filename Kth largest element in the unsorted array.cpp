#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	K=size-K+1;
	priority_queue<int> pq;
	for(int i=0;i<size;i++)
	{
		pq.push(arr[i]);
		int s=pq.size();
		if(s>K)
		{
			pq.pop();
		}
	}

	return pq.top();
}