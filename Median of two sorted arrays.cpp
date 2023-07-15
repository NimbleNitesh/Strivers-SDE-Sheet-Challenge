int calc(vector<int> &a, vector<int> &b, int pos)
{
	int l=-1e9;
	int r=1e9;
	int ans=0;
	while(l<=r)
	{
		long long int mid=(l+r)/2;
		auto it1=upper_bound(a.begin(), a.end(), mid);
		auto it2=upper_bound(b.begin(), b.end(), mid);
		int ctr=0;
		if(it1==a.end())
			ctr+=a.size();
		else
			ctr+=(it1-a.begin());
		if(it2==b.end())
			ctr+=b.size();
		else
			ctr+=(it2-b.begin());
		if(ctr<=pos)
			ans=mid+1, l=mid+1;
		else
			r=mid-1;
	}
	return ans;
}

double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n=a.size();
	int m=b.size();
	int total=(n+m)/2;
	int val=calc(a, b, total);
	if((n+m)%2==0)
		total--;
	val+=calc(a, b, total);
	// cout << "val=" << val << endl;
	// cout << calc(a, b, total) << endl;
	// cout << calc(a, b, total+1) << endl;
	return (val/2.0);
}