// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct BST{
    int val;
    struct BST *left;
    struct BST *right;
};

void insert(struct BST *root,int data){
    if(root==NULL){
        return;
    }
    
    if(root->val<data){
        if(root->right!=NULL){
            insert(root->right,data);
        }
        else
        {
            root->right = (struct BST*)malloc(sizeof(struct BST));
            root->right->val=data;
            return;
        }
    }
    else{
         if(root->left!=NULL){
            insert(root->left,data);
        }
        else
        {
            root->left = (struct BST*)malloc(sizeof(struct BST));
            root->left->val=data;
            return;
        }
        
    }

}

void inOrderTraversal(struct BST *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->val);
        inOrderTraversal(root->right);
    }
}

struct  BST *lr(struct BST *root){
    if(root->left==NULL && root->right==NULL){
        return root;
    }
    return lr(root->right);
}

//returns root->left after attaching last right of left subtree to right subtree
struct BST *helper(struct BST *curr){
    if(curr->left==NULL){
        return curr->right;
    }
    else if(curr->right==NULL){
        return curr->left;
    }
    
    struct BST *lastright = lr(curr->left);
    lastright->right=curr->right;
    return curr->left;
}

/*
void del(struct BST *root,int x){
    if(root==NULL){
        return;
    }
    if(root->val==x){
        helper(root);
        return;
    }
    struct BST *curr = root;
    while(curr!=NULL){
        if(curr->val>x){
            if(curr->left!=NULL && curr->left->val==x){
                curr->left = helper(curr->left);
                break;
            }
            else{
                curr = curr->left;
            }
        }
        else{
            if(curr->right!=NULL && curr->right->val==x){
                curr->right =  helper(curr->right);
            }
            else{
                curr=curr->right;
            }
        }
    }
}*/

struct BST *del(struct BST *root, int x) {
    if (root == NULL) {
        return NULL;
    }

    // Special case: root node needs to be deleted
    if (root->val == x) {
        struct BST *newRoot = helper(root);
        free(root);  // Free the old root node
        return newRoot;  // Return the new root
    }

    struct BST *curr = root;
    struct BST *parent = NULL;

    while (curr != NULL) {
        if (curr->val > x) {
            parent = curr;
            curr = curr->left;
        } else if (curr->val < x) {
            parent = curr;
            curr = curr->right;
        } else {
            // Node to be deleted is found
            if (parent->left == curr) {
                parent->left = helper(curr);
            } else {
                parent->right = helper(curr);
            }
            free(curr);  // Free the node being deleted
            return root; // Return the updated root (in case the root was not deleted)
        }
    }
    return root;  // Return the root if the node was not found
}


int main() {
    // Write C code here
    struct BST *b = (struct BST*)malloc(sizeof(struct BST));
    b->val = 1;
    if(b->right==NULL) printf("YES");
    insert(b,2);
    inOrderTraversal(b);
    int x =0;
    scanf("%d",&x);
    
    struct BST *c = b;
    
    //search in BST
    
    while(c!=NULL && c->val!=x){
        c = c->val>x?c->left:c->right;
    }
    if(c!=NULL){
        printf("found");
    }
    
      //deletion in BST
    c= del(c,1);
    
     scanf("%d",&x);
     
     while(c!=NULL && c->val!=x){
        c = c->val>x?c->left:c->right;
    }
    if(c!=NULL){
        printf("found");
    }
    else
    {
        printf("Not found");
    }

    return 0;
}
