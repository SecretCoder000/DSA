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
void solve(Node * root,int a,int b,int count,pair<int,int> & ans){
    if(!root){
        if(root->data == a)
            ans.first = count;
        else if(root->data == b)
            ans.second = count;
        solve(root->left,a,b,count-1,ans);
        solve(root->right,a,b,count-1,ans);
    }
}
