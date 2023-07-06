#include <string>
#include <algorithm>
#include <stack>
string reverseString(string &str){
	// Write your code here.	
	string res="";
	stack<string> full;
	int n=str.size();
	for(int i=0;i<n;i++)
	{
		if(str[i]==' ')
			continue;
		int j=i+1;
		string wrd;
		wrd.push_back(str[i]);
		while(j<n&&str[j]!=' '){
			wrd.push_back(str[j]);
			j++;
		}
		// reverse(wrd.begin(), wrd.end());
		// for(int j=0;j<wrd.size();j++)
		// 	res.push_back(wrd[j]);
		// res.push_back(' ');
		full.push(wrd);
		i=j;
	}
	// res.pop_back();
	while(!full.empty())
	{
		res+=full.top();
		res.push_back(' ');
		full.pop();
	}
	res.pop_back();
	return res;
}