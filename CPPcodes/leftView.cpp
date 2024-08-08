#include <bits/stdc++.h>
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    map<int,int> mpp;
    queue<pair<BinaryTreeNode<int> *,int>> q;

    vector<int> ans;
    if(NULL==root) return ans;
    q.push({root,0});
    while(!q.empty()){
        BinaryTreeNode<int> *node= q.front().first;
        int l = q.front().second;
        if(mpp.find(l)==mpp.end()){
            mpp[l] = node->data;
        }

        q.pop();
        if(node->right){
            q.push({node->right,l+1});
        }
        if(node->left){
            q.push({node->left,l+1});
        }
       
    }

    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}
