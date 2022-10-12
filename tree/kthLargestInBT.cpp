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

void solve(Node* root,int k,int &count,int & ans){
    if(root == NULL || count != k)
        return;
    else {
        solve(root->right,k,count,ans);
        count++;
        if(count == k)
            ans = root->data;
        solve(root->left,k,count,ans);
    }
}