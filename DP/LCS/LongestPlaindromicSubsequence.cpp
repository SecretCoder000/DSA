int LCSLength(string x,int n,string y,int m,vector<vector<int>> & dp){
    if(n == 0 || m == 0)
        return 0;
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
int longestPalindromeSubseq(string x) {
    string y = x;
    int n = x.size();
    int m = y.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
    reverse(y.begin(),y.end());
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=m;i++)
        dp[0][i] = 0;
    return LCSLength(x,n,y,m,dp);
}