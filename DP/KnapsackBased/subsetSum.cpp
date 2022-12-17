#include <bits/stdc++.h>
using namespace std;
int subsetSum(int val[],int n,int sum){
    int dp[n+1][sum+1];
    int count = 0;
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;
    for(int i =0;i<=sum;i++)
        dp[0][i] = 0;
    for(int i =1;i<=n;i++)
        for(int j = 1;j<=sum;j++){
            if(val[i-1] <= j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-val[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
            if(dp[i][j] == j)
                count++;
        }
    return count;
}

bool subsetSum(int arr[],int n,int sum,vector<vector<bool>> & ans){
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    if(ans[n][sum])
        return ans[n][sum];
    else {
        if(arr[n-1] <= sum)
            ans[n][sum] =  subsetSum(arr,n-1,sum-arr[n-1],ans) || subsetSum(arr,n-1,sum,ans);
        else
            ans[n][sum] = subsetSum(arr,n-1,sum,ans);
        return ans[n][sum];
    }
}

bool subsetSum(int arr[],int n,int sum){
    vector<vector<bool>> dp (n+1,vector<bool> (sum+1,false));
    for(int i =0;i<=n;i++)
        dp[i][0] = true;
    for(int i =1;i<=n;i++)
        for(int j = 1;j<=sum;j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    return dp[n][sum];
}
int main(){
    int n ;
    cin>>n;
    int val[n];
    int sum;
    cout<<"Enter Values : ";
    for(int i =0;i<n;i++)
        cin>>val[i];
    cout<<"Enter Sum : ";
    cin>>sum;
    cout<<subsetSum(val,n,sum);
    return 0;
}