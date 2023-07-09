#include <cstring>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	int dp[n+1][w+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			dp[i][j]=max(dp[i][j], dp[i-1][j]);
			if((j-weights[i-1])>=0)
			{
				dp[i][j]=max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]);
			}
		}
	}
	return dp[n][w];
}