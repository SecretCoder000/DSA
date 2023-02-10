int minCoins(int arr[], int M, int V) {
    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
    for(int i =1;i<=M;i++)
        dp[i][0] = 0;
    for(int i =0;i<=V;i++)
        dp[0][i] =INT_MAX-1;
    for(int i =1;i<=V;i++)
        dp[1][i] = (i%arr[0] == 0)?(i/arr[0]):(INT_MAX-1);
    for(int i =2;i<=M;i++){
        for(int j=1;j<=V;j++){
            if(arr[i-1]<=j)
                dp[i][j] = min(1+dp[i][j-arr[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[M][V]==INT_MAX-1?-1:dp[M][V];
}
