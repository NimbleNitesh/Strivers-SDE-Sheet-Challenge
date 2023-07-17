bool isValid(int mid, vector<int> &row1, vector<int> &row2, int &m, int &n, int k)
{
    int cur=0;
    auto it=upper_bound(row1.begin(), row1.end(), mid);
    cur+=((it==row1.end())?m:(it-row1.begin()));
    auto it1=upper_bound(row2.begin(), row2.end(), mid);
    cur+=((it1==row2.end())?n:(it1-row2.begin()));
    return cur<=k;
}
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    if(k==(m+n))
    {
        return max(row1[m-1], row2[n-1]);
    }
    int l=-1e9, r=1e9;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(isValid(mid, row1, row2, m, n, k-1))
        {
            ans=mid+1;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
}