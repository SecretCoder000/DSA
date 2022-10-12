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
   void solve(Node * root,int y,map<int,vector<int>> temp){
    if(root == NULL)
        return;
    else {
        auto itr = temp.find(y);
        if(itr == temp.end())
            temp.insert({y,vect{root->data}});
        else 
            itr->second.push_back(root->data);
        solve(root->left,y-1,temp);
        solve(root->right,y+1,temp);
    }
}
    vector<vector<int>> verticalTraversal(Node* root) {
        map<int,vector<int>> temp;
        solve(root,0,temp);
        vector<vector<int>> ans;
        for(auto itr = temp.begin();itr != temp.end();itr++){
            ans.push_back(itr->second);
        }
        vector<int> s1 = {1,2,3};
        vector<int> s2 = {1,2,3};
        s2.insert(s2.end(),s1.begin(),s1.end());
        return ans;
    }
int main(){

}