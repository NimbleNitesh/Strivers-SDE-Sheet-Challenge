#include <bits/stdc++.h> 
void bfs(int src, vector<int> &res, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int val=q.front();
        res.push_back(val);
        q.pop();
        for(auto i: adj[val])
        {
            if(!vis[i])
            {
                vis[i]=1;
                q.push(i);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>> adj(vertex);
    int m=edges.size();
    for(int i=0;i<m;i++)
    {
        int m1=min(edges[i].first, edges[i].second);
        int m2=max(edges[i].first, edges[i].second);
        edges[i]={m1, m2};
    }
    sort(edges.begin(), edges.end());
    for(auto i: edges)
    {
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    vector<int> res, vis(vertex, 0);
    for(int i=0;i<vertex;i++)
        if(!vis[i])
            bfs(i, res, vis, adj);
    return res;

}