bool isValid(int i, int j, int &n, vector<vector<int>> &full)
{
    //We are going column-wise. So till now anything with column>=j is unfilled.
    //Hence we check only left side
    for(int x=0;x<j;x++)
        if(full[i][x])
            return false;
    int x=i-1, y=j-1;
    while(x>=0&&y>=0)
    {
        if(full[x][y])
            return false;
        x--;
        y--;
    }
    x=i+1, y=j-1;
    while(x<n&&y>=0)
    {
        if(full[x][y])
            return false;
        x++;
        y--;
    }
    return true;
}
void solve(int &n, vector<vector<int>> &full, int col, vector<vector<int>> &res)
{
    if(col==n)
    {
        vector<int> cur;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cur.push_back(full[i][j]);
        res.push_back(cur);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isValid(i, col, n, full))
        {
            full[i][col]=1;
            solve(n, full, col+1, res);
            full[i][col]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> res;
    vector<vector<int>> full(n, vector<int> (n, 0));
    solve(n, full, 0, res);
    return res;
}