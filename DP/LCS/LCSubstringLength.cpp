int solve(string x,int n,string y,int m,vector<vector<int>> & dp){
    if(dp[n][m] == -1){
        if(x[n-1]== y[m-1])
            dp[n][m] = solve(x,n-1,y,m-1,dp)+1;
        else {
            solve(x,n-1,y,m,dp);
            solve(x,n,y,m-1,dp);
            return 0;
        }
    }
    return dp[n][m];
}

int longestCommonSubstr(string x, string y, int n, int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=m;i++)
        dp[0][i] = 0;
    int max = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = 0;
            max = max<dp[i][j]?dp[i][j]:max;
        }
    }
    return  max;
}
int main() {
    int n,m;
    n = m=6;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=m;i++)
        dp[0][i] = 0;
    solve("ABCDGH",n,"ACDGHR",m,dp);
    return 0;
}

