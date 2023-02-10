int solve(int i,int j,vector<vector<int>> & dp,vector<vector<int>> arr){
    if(arr[i][j] == 1)
        return 0;
    if(dp[i][j] == -1){
        if(dp[i-1][j] == -1)
            dp[i-1][j] = solve(i-1,j,dp,arr);
        if(dp[i][j-1] == -1)
            dp[i][j-1] = solve(i,j-1,dp,arr);
        dp[i][j] = dp[i-1][j]+dp[i][j-1];
    }
    return dp[i][j];
}
int uniquePathsWithObstacles(vector<vector<int>> & obs){
    if(obs[0][0] == 1)
        return 0;
    int a = obs.size();
    int b = obs[0].size();
    vector<vector<int>> dp(a,vector<int>(b,-1));
    dp[0][0] = 1;
    for(int i =1;i<a;i++){
        if(obs[i][0] == 1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i-1][0];
    }

    for(int i =1;i<b;i++){
        if(obs[0][i] == 1)
            dp[0][i] = 0;
        else
            dp[0][i] = dp[0][i-1];
    }
    return solve(a-1,b-1,dp,obs);
}
