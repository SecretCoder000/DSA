#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode* root, int low, int high) {
    if(root){
        int l,r;
        l=r=0;
        if(root->left->val >= low)
            l = rangeSumBST(root->left,low,high);
        if(root->right->val <= high)
            r = rangeSumBST(root->right,low,high);
        if(root->val >= low && root->val <= high)
            return root->val+l+r;
        else
            return l+r;
    }
    else
        return 0;
}