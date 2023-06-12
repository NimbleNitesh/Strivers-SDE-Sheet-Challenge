#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n=matrix.size();
	int m=matrix[0].size();
	set<int> rows, columns;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				rows.insert(i);
				columns.insert(j);
			}
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(rows.count(i))
				matrix[i][j]=0;
				// cout << 0 << ' ';
			else if(columns.count(j))
				matrix[i][j]=0;
				// cout << 0 << ' ';
		}
		// cout << '\n';
	}
}
