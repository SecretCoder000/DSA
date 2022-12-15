long long solve(vector<long long> & dp,int n){
    if(dp[n] == -1)
        dp[n] = (solve(dp,n-1)+solve(dp,n-2)+solve(dp,n-3))%1000000007;
    return dp[n];
}
long long countWays(int n){
    if(n <= 2)
        return n;
    vector<long long> dp(n,-1);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    return solve(dp,n-1);
}