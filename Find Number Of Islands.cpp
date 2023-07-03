int isValid(int i, int j, int &n, int &m)
{
   if(i<0||i>=n)
      return false;
   if(j<0||j>=m)
      return false;
   return true;
}
void dfs(int** arr, int i, int j, vector<vector<bool>> &vis, vector<pair<int, int>> &dir, int &n, int &m)
{
   vis[i][j]=1;
   for(auto x: dir)
   {
      if(isValid(i+x.first, j+x.second, n, m))
      {
         if(vis[i+x.first][j+x.second]==0&&arr[i+x.first][j+x.second])
            dfs(arr, i+x.first, j+x.second, vis, dir, n, m);
      }
   }

}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<pair<int, int>> dir={
      {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {0, 1}, {0, -1}, {-1, 0}
   };
   int ans=0;
   vector<vector<bool>> vis(n, vector<bool> (m, 0));
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         if(!vis[i][j]&&arr[i][j]){
            dfs(arr, i, j, vis, dir, n, m);
            ans++;
         }
      }
   }
   return ans;
}
