int solve(int arr[],int n,vector<int> & dp){
    if(dp[n] == -1){
        if(dp[n-1] == -1)
            dp[n-1] = solve(arr,n-1,dp);
        if(dp[n-2] == -1)
            dp[n-2] = solve(arr,n-2,dp);
        dp[n] = max(arr[n-1]+dp[n-2],dp[n-1]);
    }
    return dp[n];
}
int FindMaxSum(int arr[], int n){
    vector<int> dp(n+1,-1);
    dp[1] = arr[0];
    dp[2] = max(arr[0],arr[1]);
    return solve(arr,n,dp);
}