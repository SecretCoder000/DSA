
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

Node * LCA(Node *root,int n1,int n2){
    if(!root)
        return NULL;
    else if(root->data == n1 || root->data == n2)
        return root;
    else {
        Node * left = LCA(root->left,n1,n2);
        Node * right = LCA(root->right,n1,n2);
        if(left && right)
            return root;
        if(left)
            return left;
        else 
            return right; 
    }
}