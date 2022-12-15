#include <bits/stdc++.h>
using namespace std;
int countSubsetSum(int arr[],int n,int sum){
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i =1;i<=sum;i++)
        dp[0][i] = 0;
    for(int i = 0;i<=n;i++)
        dp[i][0] = 1;
    for(int i =1;i<=n;i++)
        for (int j = 1; j <= sum; j++) {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
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

    cout<<countSubsetSum(val,n,sum);
    return 0;
}

