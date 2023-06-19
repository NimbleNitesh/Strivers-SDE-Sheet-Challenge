bool searchMatrix(vector<vector<int>>& mat, int target) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=mat.size();
    int m=mat[0].size();
    int l=0, r=n-1;
    int row=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mat[mid][0]<=target)
        {
            row=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    // cout << row << endl;
    int column=m-1;
    l=0, r=m-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mat[row][mid]==target)
        {
            column=mid;
            break;
        }
        else if(mat[row][mid]>target)
            r=mid-1;
        else
            l=mid+1;
    }
    return mat[row][column]==target;
}