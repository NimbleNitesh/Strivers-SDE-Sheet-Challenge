int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans++;
		int j=i+1;
		while(j<n&&arr[j]==arr[i])
			j++;
		i=j-1;
	}
	return ans;
}