#include <bits/stdc++.h>

int findDuplicate(vector<int> &a, int n){
	// Write your code here.
	int freq[n];
	memset(freq, 0, sizeof(freq));
	for(int i=0;i<n;i++)
	{
		freq[a[i]]++;
		if(freq[a[i]]>1)
			return a[i];
	}
}
