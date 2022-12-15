int solve(vector<int> cost,vector<int> & dp,int n){
    if(dp[n] == -1)
        dp[n] = cost[n] +min(solve(cost,dp,n-1),solve(cost,dp,n-2));
    return dp[n];
}
int minCostClimbingStairs(vector<int> cost) {
    int n = cost.size();
    vector<int> dp(n+1,-1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    return  min(solve(cost,dp,n-1), solve(cost,dp,n-2));
}