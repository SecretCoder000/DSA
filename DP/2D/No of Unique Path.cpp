int solve(int i,int j,vector<vector<int>> & dp){
    if(dp[i][j] == -1){
        if(dp[i-1][j] == -1)
            dp[i-1][j] = solve(i-1,j,dp);
        if(dp[i][j-1] == -1)
            dp[i][j-1] = solve(i,j-1,dp);
        dp[i][j] = dp[i-1][j]+dp[i][j-1];
    }
    return dp[i][j];
}
int NumberOfPath(int a, int b){
    vector<vector<int>> dp(a,vector<int>(b,-1));
    for(int i =0;i<a;i++)
        dp[i][0] = 1;
    for(int i =1;i<b;i++)
        dp[0][i] = 1;
    return solve(a-1,b-1,dp);
}