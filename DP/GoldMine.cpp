int maxGold(int n, int m, vector<vector<int>> arr){
    vector<vector<int>> dp(n+2,vector<int> (m,-1));
    int mx = INT_MIN;
    for(int i =0;i<m;i++) {
        dp[0][i] = 0;
        dp[n+1][i] = 0;
    }
    for(int i = 1;i<=n;i++){
        dp[i][0] = arr[i-1][0];
        mx = mx<dp[i][0]?dp[i][0]:mx;
    }
    for(int j = 1;j<m;j++){
        for(int i =1;i<=n;i++){
            dp[i][j] = arr[i-1][j] + max({dp[i-1][j-1],dp[i][j-1],dp[i+1][j-1]});
            mx = mx<dp[i][j]?dp[i][j]:mx;
        }
    }
    return mx;
}