int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int> (m+2,-1));
    for(int i =0 ;i<n;i++)
        dp[i][0] = dp[i][m+1] = INT_MAX;
    int mini = INT_MAX;
    for(int i =1;i<=m;i++) {
        dp[0][i] = matrix[0][i-1];
        mini = mini>dp[0][i]?dp[0][i]:mini;
    }
    if(n == 1)
        return mini;
    else
        mini = INT_MAX;
    for(int i =1;i<n;i++){
        for(int j =1;j<=m;j++) {
            dp[i][j] = matrix[i][j - 1] + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
            if(i == n-1 && mini > dp[i][j])
                mini = dp[i][j];
        }
    }

    return mini;
}