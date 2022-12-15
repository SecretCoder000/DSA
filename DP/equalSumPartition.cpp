bool equalSumPartition(int arr[],int n,int sum1 ,int sum2){
    if(sum1 == sum2)
        return true;
    if(n == 0)
        return false;
    if(sum2<sum1)
        return equalSumPartition(arr,n-1,sum1-arr[n-1],sum2+arr[n-1]) || equalSumPartition(arr,n-1,sum1,sum2);
    else
        return equalSumPartition(arr,n-1,sum1,sum2);
}

int equalSumPartition(int arr[],int n,int sum1 ,int sum2,vector<vector<int>> & dp){
    if(sum1 == sum2)
        return 1;
    if(n == 0)
        return 0;
    if(dp[n][sum2] != -1)
        return dp[n][sum2];
    if(sum2<sum1){
        dp[n][sum2] = equalSumPartition(arr,n-1,sum1-arr[n-1],sum2+arr[n-1],dp) || equalSumPartition(arr,n-1,sum1,sum2,dp);
        return dp[n][sum2];
    }
    else{
        dp[n][sum2] =equalSumPartition(arr,n-1,sum1,sum2,dp);
        return dp[n][sum2];
    }
}
int equalSumPartition(int arr[],int n,int sum,vector<vector<int>> & ans){
    if(sum == 0 || n == 0)
        return 0;
    if(ans[n][sum] != -1)
        return ans[n][sum];
    else {
        if(arr[n-1] <= sum)
            ans[n][sum] = max(arr[n-1]+equalSumPartition(arr,n-1,sum-arr[n-1],ans),equalSumPartition(arr,n-1,sum,ans));
        else
            ans[n][sum] = equalSumPartition(arr,n-1,sum,ans);
        return ans[n][sum];
    }
}

bool equalSumPartition(int arr[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=sum;i++)
        dp[0][i] = 0;
    for(int i =1;i<=n;i++)
        for(int j =1;j<=sum;j++){
            if(arr[i-1] <= j)
                dp[i][j] = max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    return dp[n][sum] == sum;
}

bool solve(int arr[],int n,int sum,vector<vector<bool>> & ans){
    if(n == 0)
        return false;
    if(ans[n][sum] || sum == 0)
        return true;
    else {
        if(sum-arr[n-1] >= 0)
            ans[n][sum] = solve(arr,n-1,sum-arr[n-1],ans) || solve(arr,n-1,sum,ans);
        else
            ans[n][sum] = solve(arr,n-1,sum,ans);
        return ans[n][sum];
    }
}
bool equalSum(int arr[],int n,int sum){
    vector<vector<bool>> ans(n+1,vector<bool>(sum+1,false));
    return solve(arr,n,sum,ans);
}