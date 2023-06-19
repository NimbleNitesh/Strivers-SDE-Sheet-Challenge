#include <bits/stdc++.h> 
int rec(int i, int j, vector<vector<int>> &dp)
{
	if(dp[i][j]!=0)
		return dp[i][j];
	if(i>0)
	{
		if(dp[i-1][j])
			dp[i][j]+=dp[i-1][j];
		else
			dp[i][j]+=rec(i-1, j, dp);
	}
	if(j>0)
	{
		if(dp[i][j-1])
			dp[i][j]+=dp[i][j-1];
		else
			dp[i][j]+=rec(i, j-1, dp);
	}
	return dp[i][j];
}
int uniquePaths(int m, int n) {
	// Write your code here.
	//m-1 time Down and n-1 times right
	vector<vector<int>> dp(m, vector<int> (n, 0));
	dp[0][0]=1;
	return rec(m-1, n-1, dp);

}