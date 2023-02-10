int solve(Node * root,int & res){
    if(!root)
        return 0;
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    int temp = max(max(l,r)+root->data,root->data);
    int ans = max(temp,r+l+root->data);
    res = max(ans,res);
    return temp;
}
int findMaxSum(Node* root){
    int ans = INT_MIN;
    solve(root,ans);
    return ans;
}