/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int findDiameter(TreeNode<int> *root, int &height)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=0, rh=0;
    int v1=findDiameter(root->left, lh);
    int v2=findDiameter(root->right, rh);
    height=max(lh, rh)+1;
    int ans=max(v1, v2);
    ans=max(ans, (lh+rh+1));
    return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int h=0;
    return findDiameter(root, h)-1;
}
