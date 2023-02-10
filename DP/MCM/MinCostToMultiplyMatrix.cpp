//Recursve solution
int solve(int arr[],int i,int j){
    if(i>=j)
        return 0;
    int ans = INT_MAX;
    for(int k =i;k<j;k++){
        int temp = solve(arr,i,k) + solve(arr,k+1,j)+arr[i-1] * arr[k] * arr[j];
        ans = ans>temp?temp:ans;
    }
    return ans;
}
//Uisng DP
int solve(int arr[],int i,int j,vector<vector<int>> & dp){
    if(i>=j)
        return 1;
    else if(dp[i][j] == -1){
        int ans = INT_MAX;
        for(int k =i;k<j;k++){
            int l = solve(arr,i,k,dp);
            int r = solve(arr,k+1,j,dp);
            int temp = max(l*r,max(l,r));
            ans = ans>temp?temp:ans;
        }
        dp[i][j] = ans;
    }
    return dp[i][j];
}

