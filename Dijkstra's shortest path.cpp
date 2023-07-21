#include <bits/stdc++.h> 
vector<int> solve(vector<vector<pair<int, int>>> &adj, int &src, int &vertices)
{
    vector<int> dist(vertices, INT_MAX);
    dist[src]=0;
    set<pair<int, int>> full;
    full.insert({0, src});
    while(!full.empty())
    {
        auto it=full.begin();
        pair<int, int> val=*it;
        full.erase(it);
        if(dist[val.second]!=INT_MAX)
        for(auto i: adj[val.second])
        {
            if(dist[i.first]>dist[val.second]+i.second)
            {
                if(dist[i.first]!=INT_MAX)
                {
                    full.erase(full.find({dist[i.first], i.first}));
                }
                dist[i.first]=dist[val.second]+i.second;
                full.insert({dist[i.first], i.first});
            }
        }
    }
    return dist;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<vector<pair<int, int>>> adj(vertices+1);
    for(int i=0;i<edges;i++)
    {
        adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    return solve(adj, source, vertices);
}
