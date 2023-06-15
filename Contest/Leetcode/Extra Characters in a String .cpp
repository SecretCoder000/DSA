//Memoization



int solve(string str,vector<int> & dp,int index){
    if(index >= str.size())
        return 0;
    if(dp[index] == 1){
        string curStr = "";
        int minExtra = str.size();
        for(int i = index;i<str.size();++i){
            curStr.push_back(str[i]);
            int curExtra = temp.find(curStr) == temp.end()?curStr.size():0;
            int nextExtra = solve(str,dp,i+1);
            int totalExtra = curExtra+nextExtra;
            minExtra = min(minExtra,totalExtra);
        }
        dp[index] = minExtra;
    }
    return dp[index];
}
int minExtraChar(string s, vector<string>& d) {
    int n = s.size();
    for(auto it : d)
        temp.insert(it);
    vector<int> dp(n+1,-1);
    return solve(s,dp,0);
}



//Bottom Up

int minExtraChar(string str, vector<string>& d) {
    int n = str.size();
    for(auto it : d)
        temp.insert(it);
    vector<int> dp(n+1,0);
    for(int index = n-1;index>-1;--index){
        string curStr = "";
        int minExtra = n;
        for(int i = index;i<n;++i){
            curStr.push_back(str[i]);
            int curExtra = temp.find(curStr) == temp.end()?curStr.size():0;
            int nextExtra = dp[i+1];
            int totalExtra = curExtra+nextExtra;
            minExtra = min(minExtra,totalExtra);
        }
        dp[index] = minExtra;
    }
    return dp[0];
}