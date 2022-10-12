#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode* root,int lv,map<int,vector<TreeNode*>> &temp){
    if(root){
        if(lv%2 != 0){
            auto itr = temp.find(lv);
            if(itr == temp.end())
                temp.insert({lv,{root}});
            else 
                itr->second.push_back(root);
        }
        solve(root->left,lv+1,temp);
        solve(root->right,lv+1,temp);
    }
}

TreeNode* reverseOddLevels(TreeNode* root) {
    map<int,vector<TreeNode*>> temp;
    solve(root,0,temp);
    for(auto itr = temp.begin();itr != temp.end();itr++){
        vector<TreeNode*> ans = itr->second;
        for(int i =0;i<ans.size()/2;i++)
            swap(ans[i]->val,ans[ans.size()-1-i]->val);
    }
    return root;
}
int main(){
    return 0;
}