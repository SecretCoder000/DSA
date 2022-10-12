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
void solve(Node *root,map<int,int> & ans,int lv){
    if(root == NULL)
        return;
    else {
        if(ans.find(lv) == ans.end())
            ans.insert({lv,root->data});
        solve(root->left,ans,lv+1);
        solve(root->right,ans,lv+1);
    }
}
vector<int> leftView(Node *root){
   map<int,int> temp;
   solve(root,temp,1);
   vector<int> ans;
   for(auto itr = temp.begin();itr != temp.end();itr++)
        ans.push_back(itr->second);
    return ans;
}