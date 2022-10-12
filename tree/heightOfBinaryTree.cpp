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

void solve(Node * root,int & h){
    if(root == NULL){
        return ;
    }   
    else {
        h++;
        solve(root->left,h);
        solve(root->right,h);
    }
}