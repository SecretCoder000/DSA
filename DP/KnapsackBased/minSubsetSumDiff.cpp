#include <bits/stdc++.h>
using namespace std;
int minDifference(int arr[], int n) {
    int temp = 0;
    for(int i =0;i<n;i++)
        temp += arr[i];
    int sum = temp/2;
    int dp[n+1][sum+1];
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=sum;i++)
        dp[0][i] = 0;
    for(int i =1;i<=n;i++)
        for(int j =1;j<=sum;j++){
            if(arr[i-1] <= j)
                dp[i][j] = max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    return temp-2*dp[n][sum];
}