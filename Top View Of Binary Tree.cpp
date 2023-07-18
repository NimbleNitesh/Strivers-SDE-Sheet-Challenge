#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void traverse(TreeNode<int> *root, vector<pair<int, int>> &res)
{
    queue<pair<TreeNode<int>* , int>> q; 
    int cur=0;
    set<int> vis;
    q.push({root, cur});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        if(vis.find(it.second)==vis.end())
            res.push_back({it.second, (it.first)->val});

        vis.insert(it.second);
        if((it.first)->left!=NULL)
        {
            q.push({(it.first)->left, (it.second)-1});
        }
        if((it.first)->right!=NULL)
        {
            q.push({(it.first)->right, (it.second)+1});
        }
    }
}
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root==NULL)
        return {};
    vector<pair<int, int>> res;
    traverse(root, res);
    sort(res.begin(), res.end());
    vector<int> ans;
    for(auto i: res)
        ans.push_back(i.second);
    return ans;
}