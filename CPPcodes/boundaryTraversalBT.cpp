/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <bits/stdc++.h>
void f(TreeNode<int> *root,vector<int> &leaf){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL) leaf.push_back(root->data);
    f(root->left,leaf);
    f(root->right,leaf);
}
void l(TreeNode<int> *root,vector<int> &leaf){
    if(root==NULL) return;
    if(root->left ==NULL && root->right==NULL){
        return;
    }
    leaf.push_back(root->data);
    if(root->left!=NULL){
        l(root->left,leaf);
    }
    else{
        l(root->right,leaf);
    }
}
void r(TreeNode<int> *root,vector<int> &rev){
    if(root==NULL) return;
    if(root->left ==NULL && root->right==NULL){
        return;
    }
    rev.push_back(root->data);
    if(root->right!=NULL){
        r(root->right,rev);
    }
    else{
        r(root->left,rev);
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
        vector<int> leaf;

    if(root == NULL) {
        return leaf;
    }

    // if(!(root->left == NULL && root->right == NULL)) {
        leaf.push_back(root->data);
    //}
    l(root->left,leaf);
    f(root,leaf);
    vector<int> rev;
    r(root->right,rev);
    reverse(rev.begin(),rev.end());

    for(int i=0;i<rev.size();i++){
        leaf.push_back(rev[i]);
    }
    return leaf;
    
}   
