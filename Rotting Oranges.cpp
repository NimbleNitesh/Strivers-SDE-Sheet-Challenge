#include <queue>
#include <vector>
bool isValid(int i, int j, int n, int m)
{
    if(i<0||i>=n)
        return 0;
    if(j<0||j>=m)
        return 0;
    return 1;
}
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<pair<int, int>> dir={
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==2){
                q.push({i, j});
                vis[i][j]=1;
                dist[i][j]=0;
            }
    while(!q.empty())
    {
        pair<int, int> val=q.front();
        q.pop();
        for(auto j: dir)
        {
            int i1=val.first+j.first;
            int i2=val.second+j.second;
            if(isValid(i1, i2, n, m))
            {
                if(!vis[i1][i2]&&grid[i1][i2]==1)
                {
                    vis[i1][i2]=1;
                    q.push({i1, i2});
                    dist[i1][i2]=dist[val.first][val.second]+1;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==1)
            {
                if(dist[i][j]==-1)
                    return -1;
                ans=max(ans, dist[i][j]);
            }
    return ans;
}