int solve(string x,string y){
    int n = x.size();
    int m = y.size();
    if(n == 0 || m == 0)
        return 0;
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=m;i++)
        dp[0][i] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int minDistance(string word1, string word2) {
    return word1.size()+word2.size()-2*solve(word1,word2);
}