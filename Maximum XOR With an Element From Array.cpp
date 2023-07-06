#include <vector>
#include <algorithm>
class node{
	public:
	node* data[2];
	node()
	{
		data[0]=NULL;
		data[1]=NULL;
	}
};
class trie{
	public:
	node* root;
	trie()
	{
		root=new node();
	}
	//0 to 31 bits will be checked
	void insert(int n)
	{
		node* temp=root;
		for(int i=31;i>=0;i--)
		{
			int parity=(n&(1<<i))>0;
			if(temp->data[parity]==NULL)
			{
				node* cur=new node();
				temp->data[parity]=cur;
			}
			temp=temp->data[parity];
		}
	}
	int query(int x)
	{
		node* temp=root;
		int res=0;
		for(int i=31;i>=0;i--)
		{
			int req=((x&(1<<i))>0);
			req^=1;
			if(temp->data[req]==NULL)
			{
				req^=1;
				if(req)
					res|=(1<<i);
				temp=temp->data[req];
			}
			else
			{
				if(req)
					res|=(1<<i);
				temp=temp->data[req];
			}
		}
		return res;
	}
};
bool customsort(vector<int> &a, vector<int> &b)
{
	return a[1]<b[1];
}
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	int n=arr.size();
	int m=queries.size();
	trie tr;
	sort(arr.begin(), arr.end());
	for(int i=0;i<m;i++)
		queries[i].push_back(i);
	sort(queries.begin(), queries.end(), customsort);
	vector<int> ans(m, -1);
	int ptr_arr=0, ptr_qry=0;
	while(ptr_qry<m&&arr[0]>queries[ptr_qry][1])
		ptr_qry++;
	while(ptr_qry<m)
	{
		while(ptr_arr<n&&arr[ptr_arr]<=queries[ptr_qry][1])
		{
			tr.insert(arr[ptr_arr]);
			ptr_arr++;
		}
		// cout << "ptr_arr=" << ptr_arr << '\n';
		ans[queries[ptr_qry][2]]=tr.query(queries[ptr_qry][0]);
		ans[queries[ptr_qry][2]]^=queries[ptr_qry][0];
		ptr_qry++;
	}
	return ans;
}