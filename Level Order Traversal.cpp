#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(BinaryTreeNode<int> *root, vector<int> &res)
{
    if(root==NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int>* cur=q.front();
        res.push_back(cur->val);
        q.pop();
        BinaryTreeNode<int>* l=cur->left;
        BinaryTreeNode<int>* r=cur->right;
        if(l)
            q.push(l);
        if(r)
            q.push(r);
    }
}
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(root==NULL)
        return {};
    vector<int> res;
    solve(root, res);
    return res;

}