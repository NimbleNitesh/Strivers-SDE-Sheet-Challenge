#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int> &res)
{
    if(root==NULL)
        return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
void preorder(BinaryTreeNode<int> *root, vector<int> &res)
{
    if(root==NULL)
        return;
    res.push_back(root->data);
    preorder(root->left, res);
    preorder(root->right, res);
}
void postorder(BinaryTreeNode<int> *root, vector<int> &res)
{
    if(root==NULL)
        return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    BinaryTreeNode<int> *temp=root;
    vector<vector<int>> full(3);
    inorder(root, full[0]);
    root=temp;
    preorder(root, full[1]);
    root=temp;
    postorder(root, full[2]);
    return full;
}