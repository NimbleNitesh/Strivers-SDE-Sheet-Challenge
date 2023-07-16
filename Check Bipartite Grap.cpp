bool checkBipartite(int node, int color, vector<vector<int>> &adj, vector<int> &vis)
{
	vis[node]=color;
	color^=1;
	// bool res=true;
	for(auto i: adj[node])
	{
		if(vis[i]==-1)
		{
			bool ch=checkBipartite(i, color, adj, vis);
			if(ch==false)
				return false;
		}
		else
		{
			if(vis[i]!=color)
				return false;
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges.size();
	vector<vector<int>> adj(n);
	vector<int> vis(n, -1);
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
			if(edges[i][j])
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
	}
	bool res=1;
	for(int i=0;i<n;i++)
	{
		if(vis[i]==-1)
			res&=checkBipartite(i, 0, adj, vis);
	}
	return res;

}