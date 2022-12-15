nt solve(int n,vector<int> & dp){
    if(dp[n] == -1){
        int a = solve(n/2,dp);
        int b = solve(n/3,dp);
        int c = solve(n/4,dp);
        if(a+b+c > dp[n])
            dp[n] = a+b+c;
    }
    return dp[n];
}
int maxSum(int n){
    if(n <= 11)
        return n;
    vector<int> dp(n+1,-1);
    for(int i =0;i<=11;i++)
        dp[i] = i;
    return solve(n,dp);
}