long long solve(string x,string y){
    int n = x.size();
    int m = y.size();
    vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
    for(int i =0;i<=m;i++)
        dp[0][i] = 0;
    for(int i =0;i<=n;i++)
        dp[i][0] = 1;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}
string toBinary(long long n){
    string str;
    while (n > 0){
        long long r = n%2;
        str.insert(str.begin(),r+48);
        n/=2;
    }
    return str;
}
long long count101(long long n) {
    string x,y;
    x = toBinary(n);
    y = "101";
    return solve(x,y);
}