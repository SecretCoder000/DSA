long long solve(vector<vector<long long>> & dp,long long n,long long m){
    if(dp[n][m] == -1)
        dp[n][m] = (solve(dp,n-1,m)+solve(dp,n,m-1))%1000000007;
    return dp[n][m];
}
long long numberOfPaths(long long m, long long n){
    vector<vector<long long>> dp(n,vector<long long> (m,-1));
    for(long long i =1;i<n;i++)
        dp[i][0] = 1;
    for(long long i =1;i<m;i++)
        dp[0][i] = 1;
    dp[0][0] = 0;

    return solve(dp,n-1,m-1);
}