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
void preOrderTraversal(Node * root,vector<int> & ans){
    if(root == NULL)
        return;
    else {
        ans.push_back(root->data);
        preOrderTraversal(root->left,ans);
        preOrderTraversal(root->right,ans);
    }
}