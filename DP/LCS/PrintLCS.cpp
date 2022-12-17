
vector<string> solve(string x,int n,string y,int m,vector<vector<int>>  dp){
    int i = n,j = m;
    vector<vector<string>> dp2 (n+1,vector<string>(m+1,""));
    queue<pair<int,int>> st;
    st.push({n,m});
    while (!st.empty()){
        pair<int,int> temp = st.front();
        st.pop();
        if(temp.first == 0 || temp.second == 0)
            continue;
        if(x[temp.first-1] == y[temp.second-1]){
                st.push({temp.first - 1, temp.second - 1});
                string str = dp2[temp.first][temp.second];
                str.insert(str.begin(),x[temp.first-1]);
                dp2[temp.first-1][temp.second-1] = str;

        }else {
            if(dp[temp.first-1][temp.second] == dp[temp.first][temp.second-1]) {
                st.push({temp.first - 1, temp.second});
                st.push({temp.first, temp.second - 1});
                dp2[temp.first-1][temp.second] = dp2[temp.first][temp.second];
                dp2[temp.first][temp.second-1] = dp2[temp.first][temp.second];
            }else {
                if(dp[temp.first-1][temp.second] > dp[temp.first][temp.second-1]){
                    st.push({temp.first-1,temp.second});
                    dp2[temp.first-1][temp.second] = dp2[temp.first][temp.second];
                }else {
                    st.push({temp.first, temp.second - 1});
                    dp2[temp.first][temp.second-1] = dp2[temp.first][temp.second];
                }
            }
        }
    }
    set<string> str;
    for(int i =0;i<=n;i++)
        if(dp2[i][0].size() == dp[n][m])
            str.insert(dp2[i][0]);
    for(int i =0;i<=m;i++)
        if(dp2[0][i].size() == dp[n][m])
            str.insert(dp2[0][i]);
    return vector<string> {str.begin(),str.end()};
}