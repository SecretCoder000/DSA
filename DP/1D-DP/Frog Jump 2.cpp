#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> & cost,int k,vector<int> & dp){
    if(dp[n] == -1) {
        int mn = INT_MAX;
        for(int i = 1;i<=k;i++) {
            dp[n-i] = solve(n-i,cost,k,dp);
            int temp = abs(cost[n-1-i]-cost[n-1])+dp[n-i];
            mn = min(mn,temp);
        }
        dp[n] = mn;
    }
    return dp[n];
}




int main() {
    vector<int> arr = {40 ,10 ,20, 70, 80 ,10 ,20, 70, 80 ,60};
    vector<int> dp(arr.size()+1,-1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(arr[0]-arr[1]);
    cout<<solve(arr.size(),arr,4,dp);
    return 0;
}
