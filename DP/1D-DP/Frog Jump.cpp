int solve(int n, vector<int> & h,vector<int> & dp){
    if(dp[n] == -1) {
        dp[n - 1] = solve(n - 1, h, dp);
        dp[n - 2] = solve(n - 2, h, dp);
        dp[n] = min(abs(h[n - 1] - h[n - 2]) + dp[n - 1], abs(h[n - 1] - h[n - 3]) + dp[n - 2]);
    }
    return dp[n];
}
int frogJump(int n, vector<int> &arr){
    vector<int> dp(arr.size()+1,-1);
    dp[0] = INT_MAX;
    dp[1] = 0;
    dp[2] = abs(arr[0]-arr[1]);
    return solve(n,arr,dp);
}