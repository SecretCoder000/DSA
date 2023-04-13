int dp[25][200];
int solve(vector<int> & arr,int n,int k,int i,int x){
    if(i==n){
        if(x==k)
            return 1;
        else
            return 0;
    }
    if(dp[i][x] != -1)
        return dp[i][x];
    int ans = 0;
    int a1 =  solve(arr,n,k,i+1,x^arr[i]);
    int a2 = solve(arr,n,k,i+1,x);
    ans = a1+a2;
    dp[i][x] = ans;
    return ans;
}
int subsetXOR(vector<int> arr, int n, int k) {
    memset(dp,-1,sizeof(dp));
    return solve(arr,n,k,0,0);
}