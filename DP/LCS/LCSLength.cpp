#include <bits/stdc++.h>
using namespace std;
//Recursive Solution

int solve(string x,int n,string y,int m){
    if(n == -1 || m == -1)
        return 0;
    if(x[n] == y[m])
        return solve(x,n-1,y,m-1)+1;
    else
        return max(solve(x,n,y,m-1), solve(x,n-1,y,m));
}
//Memoization
int solve(string x,int n,string y,int m,vector<vector<int>> & dp){
    if(dp[n][m] == -1) {
        if (x[n-1] == y[m-1])
            dp[n][m] =  solve(x, n - 1, y, m - 1,dp) + 1;
        else
            dp[n][m] = max(solve(x, n, y, m - 1,dp), solve(x, n - 1, y, m,dp));
    }
    return dp[n][m];
}
//Top Down
int solve(string x,string y){
    int n = x.size();
    int m = y.size();
    if(n == 0 || m == 0)
        return 0;
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=m;i++)
        dp[0][i] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}



int longestCommonSubsequence(string str1, string str2) {
    return solve(str1,str2);
}

