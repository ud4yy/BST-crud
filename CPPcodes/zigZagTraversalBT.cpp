#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{   if (!root) return {};  // Handle the case of an empty tree
    // Write your code here!
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    vector<int> ans;
    bool lr=true;

    while(!q.empty()){
       
        int n=q.size();
        vector<int> inter(n,0);
        for(int i=0;i<n;i++){
            BinaryTreeNode<int> *node=q.front();
            inter[i]=node->data;
            q.pop();

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        if(lr!=false){
            ans.insert(ans.end(),inter.begin(),inter.end());
        }
        else{
            reverse(inter.begin(),inter.end());
            ans.insert(ans.end(),inter.begin(),inter.end());
        }
        lr=!lr;
    }
    return ans;
}
