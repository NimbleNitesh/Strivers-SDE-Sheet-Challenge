#include <bits/stdc++.h> 
bool isValid(int i, int j, vector<vector<int>> &maze, int &n)
{
  if(i<0||i>=n)
    return false;
  if(j<0||j>=n)
    return false;
  if(maze[i][j]==0)
    return false;
  return true;
}
int convert(int i, int j, int &n)
{
  return (n*i+j);
}
pair<int, int> convert_inverse(int i, int &n)
{
  return {i/n, i%n};
}
void recursive(int i, int j, vector<int> &vis, vector<vector<int>> &res, int &n, vector<vector<int>> &maze)
{
  if(i==(n-1)&&j==(n-1))
  {
    int ind=convert(i, j, n);
    if(!vis[ind]){
    vis[ind]=1;
    res.push_back(vis);
    vis[ind]=0;
    }
    return;
  }
  int index=convert(i, j, n);
  if(vis[index])
    return;
  vis[index]=1;
  // cout << i << ' ' << j << endl;
  if(isValid(i+1, j, maze, n))
  {
    // int index=convert(i+1, j, n);
    // if(!vis[index]){
    // vis[index]=1;
    recursive(i+1, j, vis, res, n, maze);
    // vis[index]=0;
    // }
  }
  if(isValid(i, j+1, maze, n))
  {
    // int index=convert(i, j+1, n);
    // if(!vis[index]){
    // vis[index]=1;
    recursive(i, j+1, vis, res, n, maze);
    // vis[index]=0;
    // }
  }
  if(isValid(i-1, j, maze, n))
  {
    // int index=convert(i-1, j, n);
    // if(!vis[index]){
    // vis[index]=1;
    recursive(i-1, j, vis, res, n, maze);
    // vis[index]=0;
    // }
  }
  if(isValid(i, j-1, maze, n))
  {
    // int index=convert(i, j-1, n);
    // if(!vis[index]){
    // vis[index]=1;
    recursive(i, j-1, vis, res, n, maze);
    // vis[index]=0;
    // }
  }
  vis[index]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<int> vis(n*n, 0);
  vector<vector<int>> res;
  recursive(0, 0, vis, res, n, maze);
  return res;
}