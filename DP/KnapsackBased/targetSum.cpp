#include <bits/stdc++.h>
using namespace std;
/*Recursive Solution*/
void solve(int arr[],int n,int sum,int target,int & count){
    if(n == 0){
        if(sum == target)
            count++;
    }else {
        solve(arr,n-1,sum+arr[n-1],target,count);
        solve(arr,n-1,sum-arr[n-1],target,count);
    }
}
int findTargetSumWays(vector<int>& nums, int target) {
    int count = 0;
    solve(nums.data(),nums.size(),0,target,count);
    return count;
}

/*Using dp*/
int solve(int arr[],int n,int target){
    int sum = 0;
    for(int i =0;i<n;i++)
        sum += arr[i];
    int diff = (sum+target)/2;
    int dp[n+1][diff+1];
    for(int i =0;i<=diff;i++)
        dp[0][i] = 0;
    for(int i =0;i<=n;i++)
        dp[i][0] = 1;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=diff;j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][diff];
}
