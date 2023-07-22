#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void left_boundary(TreeNode<int> *root, vector<int> &res)
{
    if(root==NULL)
        return;
    if(root->left!=NULL||root->right!=NULL)
        res.push_back(root->data);
    if(root->left!=NULL)
        left_boundary(root->left, res);
    else if(root->right!=NULL)
        left_boundary(root->right, res);
}
void right_boundary(TreeNode<int> *root, vector<int> &res)
{
    if(root==NULL)
        return;
    if(root->left!=NULL||root->right!=NULL)
        res.push_back(root->data);
    if(root->right!=NULL)
        right_boundary(root->right, res);
    else if(root->left!=NULL)
        right_boundary(root->left, res);
}
void leaf_boundary(TreeNode<int> *root, vector<int> &res)
{
    if(root==NULL)
        return;
    if(((root->left)==NULL)&&((root->right)==NULL))
        res.push_back(root->data);
    leaf_boundary(root->left, res);
    leaf_boundary(root->right, res);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> a, b;
    TreeNode<int> *temp=root;
    if(root==NULL)
        return {};
    if(((root->left)==NULL)&&((root->right)==NULL))
    {
        return {root->data};
    }
    if(root->left==NULL)
    {
        a.push_back(root->data);
        leaf_boundary(root, a);
        root=temp;
        right_boundary(root->right, b);
        reverse(b.begin(), b.end());
        for(auto i: b)
            a.push_back(i);
        return a;
    }
    if(root->right==NULL)
    {
        a.push_back(root->data);
        left_boundary(root->left, a);
        root=temp;
        leaf_boundary(root, a);
        return a;
    }
    a.push_back(root->data);
    left_boundary(root->left, a);
    root=temp;
    leaf_boundary(root, a);
    root=temp;
    right_boundary(root->right, b);
    reverse(b.begin(), b.end());
    for(auto i: b)
        a.push_back(i);
    return a;
}