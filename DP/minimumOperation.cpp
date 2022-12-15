int minOperation(int n){
    vector<int> dp(n+1,0);
    dp[0] = 0;
    for(int i = 1;i<=n;i++){
        if(i%2 != 0)
            dp[i] = dp[i-1]+1;
        else
            dp[i] = min(dp[i/2],dp[i-1])+1;
    }
    return dp[n];
}