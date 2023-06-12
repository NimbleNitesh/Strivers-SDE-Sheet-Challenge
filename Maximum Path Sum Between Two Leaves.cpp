#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int possible_ans=LONG_MIN;
long long int recursive(TreeNode<int> *root)
{
    if(root==NULL)
        return 0;
    long long int left_sum=recursive(root->left);
    long long int right_sum=recursive(root->right);
    long long int res=root->val+max(left_sum, right_sum);
    possible_ans=max(possible_ans, left_sum+right_sum+root->val);
    return res;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL)
        return -1;
    if(root->left==NULL)
        return -1;
    if(root->right==NULL)
        return -1;
    long long int left_path=recursive(root->left);
    long long int right_path=recursive(root->right);
    long long int res=left_path+right_path+root->val;
    res=max(res, possible_ans);
    possible_ans=LONG_MIN;
    return res;

}