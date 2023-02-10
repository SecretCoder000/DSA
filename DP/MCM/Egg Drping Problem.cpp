#include <bits/stdc++.h>
using namespace std;
//Recursive
int eggDrop(int e, int f){
    if(f <= 1 || e == 1)
        return f;
    int ans = INT_MAX;
    for(int k = 1;k<=f;k++){
        int temp = 1+ max(eggDrop(e-1,k-1), eggDrop(e,f-k));
        ans = ans>temp?temp:ans;
    }
    return ans;
}

// Using DP

int solve(int e, int f,vector<vector<int>> & dp){
    if(f <= 1 || e == 1)
        return f;
    if(dp[e][f] != -1)
        return dp[e][f];
    int ans = INT_MAX;
    for(int k = 1;k<=f;k++){
        int bottom,top;
        if(dp[e-1][k-1] != -1)
            bottom = dp[e-1][k-1];
        else {
            bottom = solve(e-1,k-1,dp);
            dp[e-1][k-1] = bottom;
        }
        if(dp[e][f-k] != -1)
            top = dp[e][f-k];
        else {
            top = solve(e,f-k,dp);
            dp[e][f-k] = top;
        }
        int temp = 1+ max(bottom,top);
        ans = ans>temp?temp:ans;
    }
    dp[e][f] = ans;
    return ans;
}

int solve(int e, int f,vector<vector<int>> & dp){
    if(f <= 1 || e == 1)
        return f;
    if(dp[e][f] != -1)
        return dp[e][f];
    int ans = INT_MAX;
    int l = 1,r = f;
    while (l<=r){
        int mid = (l+r)/2;
        int bottom,top;
        if(dp[e-1][mid-1] != -1)
            bottom = dp[e-1][mid-1];
        else {
            bottom = solve(e-1,mid-1,dp);
            dp[e-1][mid-1] = bottom;
        }
        if(dp[e][f-mid] != -1)
            top = dp[e][f-mid];
        else {
            top = solve(e,f-mid,dp);
            dp[e][f-mid] = top;
        }
        int temp = 1+ max(bottom,top);
        ans = ans>temp?temp:ans;
        if(bottom < top)
            l = mid+1;
        else
            r = mid-1;
    }

    dp[e][f] = ans;
    return ans;
}
int main() {
    int e,f;
    e = 4;
    f = 10000;
    vector<vector<int>> dp(e+1,vector<int>(f+1,-1));
    for(int i = 1;i<=f;i++)
        dp[0][i] = INT_MAX;
    for(int i =0;i<=e;i++)
        dp[i][0] = 0;
    cout<<solve(e,f,dp);
    return 0;
}
