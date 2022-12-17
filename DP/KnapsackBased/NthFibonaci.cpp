long long int solve(long long int n,vector<long long int> & dp){
    if(dp[n] == -1)
        dp[n] = (solve(n-1,dp)+solve(n-2,dp))%1000000007;
    return dp[n];
}
long long int nthFibonacci(long long int n){
    if(n <= 1)
        return n;
    vector<long long int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    solve(n,dp);
    return dp[n];
}