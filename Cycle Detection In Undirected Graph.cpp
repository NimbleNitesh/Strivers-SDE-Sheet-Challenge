bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int node, int parent)
{
    vis[node]=1;
    bool res=1;
    for(auto i: adj[node])
    {
        if(vis[i])
        {
            if(parent!=-1&&i!=parent){
                // cout << "exe\n";
                res=0;
                return false;
            }
        }
        else
        {
            res&=dfs(adj, vis, i, node);
        }
    }
    return res;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n);
    vector<bool> vis(n, 0);
    for(auto i: edges)
    {
        adj[i[0]-1].push_back(i[1]-1);
        adj[i[1]-1].push_back(i[0]-1);
    }
    for(int i=0;i<n;i++)
    if(!vis[i])
    if(!dfs(adj, vis, i, -1))
        return "Yes";
    return "No";
}
