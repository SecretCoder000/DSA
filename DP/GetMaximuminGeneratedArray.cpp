int getMaximumGenerated(int n) {
    if(n <= 1)
        return n;
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    int max = INT_MIN;
    for(int i = 2;i<=n;i++){
        if(i%2 == 0)
            dp[i] = dp[i/2];
        else
            dp[i] = dp[(i-1)/2]+dp[(i-1)/2+1];
        max = max<dp[i]?dp[i]:max;
    }
    return max;
}