int solve(string x,int n,string y,int m,vector<vector<int>> & dp){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        };
    }
    return dp[n][m];
}

string printLCS(string x,int n,string y,int m,vector<vector<int>> & dp){
    int i,j;
    i =n;j=m;
    string str;
    while (i > 0 && j > 0){
        if(x[i-1] == y [j-1]){
            str.insert(str.begin(),x[i-1]);
            i--;j--;
        }else {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    return str;
}

string shortestCommonSupersequence(string x, string y) {
    int n = x.size();
    int m = y.size();
    if(n == 0 || m == 0)
        return "";
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=m;i++)
        dp[0][i] = 0;
    solve(x,n,y,m,dp);
    string str = printLCS(x,n,y,m,dp);
    int i,j,k;
    i=j=k=0;
    int p = str.size();
    string ans;
    while (i < n && j < m && k < p){
        if(x[i] == y[j] && y[j] == str[k]){
            ans.push_back(x[i]);
            i++;
            j++;
            k++;
        }
        else if(x[i] != y[j] && y[j] == str[k]){
            ans.push_back(x[i]);
            i++;
        }else if(x[i] != y[j] && x[i] == str[k]){
            ans.push_back(y[j]);
            j++;
        }else {
            ans.push_back(x[i]);
            i++;
        }
    }
    while (i < n)
        ans.push_back(x[i++]);
    while (j < m)
        ans.push_back(y[j++]);
    return ans;
}