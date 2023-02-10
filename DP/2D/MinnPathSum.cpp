int minPathSum(vector<vector<int>>& grid) {
    int a = grid.size();
    int b = grid[0].size();
    vector<vector<int>> dp(a,vector<int>(b,-1));
    dp[0][0] = grid[0][0];
    for(int i =1;i<a;i++)
        dp[i][0] = grid[i][0]+dp[i-1][0];
    for(int i =1;i<b;i++)
        dp[0][i] = grid[0][i]+dp[0][i-1];
    for(int i =1;i<a;i++){
        for(int j =1;j<b;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
    }
    return dp[a-1][b-1];
}