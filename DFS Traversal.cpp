bool customsort(vector<int> &a, vector<int> &b)
{
    return a[0]<b[0];
}
void dfs(int node, vector<int> &temp, vector<bool> &vis, vector<vector<int>> &adj)
{
    temp.push_back(node);
    vis[node]=1;
    for(auto i: adj[node])
    {
        if(!vis[i])
        {
            dfs(i, temp, vis, adj);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V);
    vector<vector<int>> res;
    vector<bool> vis(V, 0);
    sort(edges.begin(), edges.end(), customsort);
    for(int i=0;i<E;i++)
    {
        int l=min(edges[i][0], edges[i][1]);
        int r=max(edges[i][0], edges[i][1]);
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    for(int i=0;i<V;i++)
    {
        if(vis[i])
            continue;
        vector<int> temp;
        dfs(i, temp, vis, adj);
        res.push_back(temp);
    }
    return res;
}