#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int> full;
	for(int i=0;i<n;i++)
	 	full.push(i);
	while(full.size()>1)
	{
		int v1=full.top();
		full.pop();
		int v2=full.top();
		full.pop();
		if(knows(v1, v2))
			full.push(v2);
		else
			full.push(v1);
	}
	int poss=full.top();
	for(int i=0;i<n;i++)
	{
		if(poss!=i)
		{
			if(!knows(i, poss))
				return -1;
			if(knows(poss, i))
				return -1;
		}
	}
	return poss;
}