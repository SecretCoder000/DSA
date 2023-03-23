long long solve(string x,string y){
    int n = x.size();
    int m = y.size();
    vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
    for(int i =0;i<=m;i++)
        dp[0][i] = 0;
    for(int i =0;i<=n;i++)
        dp[i][0] = 1;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}