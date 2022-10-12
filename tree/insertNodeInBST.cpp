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
void solve(Node* root,int key){
    if(key < root->data){
        if(!root->left){
            Node * temp = new Node(key);
            root->left = temp;
            return;
        }else 
            insert(root->left,key);
    }else {
        if(!root->right){
            Node * temp = new Node(key);
            root->right = temp;
            return;
        }else 
            insert(root->right,key);
    }
}
Node* insert(Node* root,int key){
    if(root == NULL)
        return new Node(key);
    solve(root,key);
    return root;
}