#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int sum) {
    int count = 0;
    int n = coins.size();
    int dp[n+1][sum+1];
    for(int i = 1;i<=n;i++)
        dp[i][0] = 0;
    for(int i = 1;i<=n;i++)
        dp[i][0] = 0;
}

int main() {

    return 0;
}