#include <bits/stdc++.h>
using namespace std;

bool isPlaindrom(string str,int i,int j){
    while(i<j) {
        if (str[i] != str[j])
            return false;
        i++,j--;
    }
    return true;
}
//Without using DP
int solve(string str,int i,int j ){
    if(i>=j)
        return 0;
    else if(isPlaindrom(str,i,j))
        return 0;
    int ans = INT_MAX;
    for(int k =i;k<j;k++){
        int temp = solve(str,i,k)+ solve(str,k+1,j) +1;
        ans = ans>temp?temp:ans;
    }
    return ans;
}
//With DP
int solve(string str,int i,int j ,vector<vector<int>> & dp){
    if(i>=j)
        return 0;
    else if(dp[i][j] != -1)
        return dp[i][j];
    else if(isPlaindrom(str,i,j)){
        dp[i][j] = 0;
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k =i;k<j;k++){
        int temp = solve(str,i,k,dp)+solve(str,k+1,j,dp)+1;
        ans = ans>temp?temp:ans;
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int main() {
    string str = "ababbbabbababa";
    int n = str.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<solve(str,0,str.size()-1,dp);
    return 0;
}