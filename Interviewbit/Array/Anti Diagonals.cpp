vector<vector<int> > Solution::diagonal(vector<vector<int> > &a) {
    int n = a.size();
    vector<vector<int>> ans(2*n-1);
    for(int i =0;i<n;i++)
        for(int j = 0;j<n;j++)
            ans[i+j].push_back(a[i][j]);
    return ans;
}