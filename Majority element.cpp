#include <bits/stdc++.h>
const int maxn=2e5+7;
const int delta=1e5;
int freq[maxn];
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	memset(freq, 0, sizeof(freq));
	int ans=INT_MIN;
	int val=INT_MIN;
	for(int i=0;i<n;i++){
		freq[delta+arr[i]]++;
		if(ans<freq[delta+arr[i]])
		{
			ans=freq[delta+arr[i]];
			val=arr[i];
		}
	}
	int req=(n>>1);
	if(ans>req)
		return val;
	else
		return -1;

}