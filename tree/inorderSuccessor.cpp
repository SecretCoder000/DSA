
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left,*right;
    Node(int x){
        data = x;
        left=right=NULL;
    }
};

Node * inOrderSuccessor(Node *root, Node *x){
    if(!root)
        return root;
    else {
        if(root->left && root->left == x)
            return root;
        else if(root->right && root->right == x)
            return root;
        if(x->data < root->data)    
            return inOrderSuccessor(root->left,x);
        return inOrderSuccessor(root->right,x);
    }
}