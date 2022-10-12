
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
void levelOrderTraversal(queue<Node*> st,vector<vector<Node*>> & ans){
    if(st.empty())
        return;
    else {
        vector<Node*> temp;
        queue<Node*> res;
        while (!st.empty()){
            temp.push_back(st.front());
            if(st.front()->left)
                res.push(st.front()->left);
            if(st.front()->right)
                res.push(st.front()->right);
            st.pop();
        }
        ans.push_back(temp);
        levelOrderTraversal(res,ans);
    }
}
bool complete(Node * root){
    vector<vector<Node*>> ans;
    queue<Node*> q;
    q.push(root);
    levelOrderTraversal(q,ans);
    if(ans.size() <= 1)
        return true;
    int count = 1;
    for(int i =0;i<ans.size()-1;i++){
        if(ans[i].size() != count)
            return false;
        count *= 2;
    }
    vector<Node*> temp = ans[ans.size()-2];
    for(int i = 0;i<temp.size();i++)
        if(!temp[i]->left && temp[i]->right)
            return false;
    return true;
}