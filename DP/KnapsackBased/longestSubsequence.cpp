int longestSubsequence(int n, int arr[]){
    vector<int> dp(n,-1);
    dp[0] = 1;
    int max = INT_MIN;
    for(int i =0;i<n;i++){
        pair<int,int> temp = {INT_MIN,-1};
        for(int j = i-1;j>-1;j--){
            if(arr[j]-1 == arr[i] || arr[j]+1 == arr[i]){
                if(temp.second == -1 || dp[j] > temp.first){
                    temp.first = dp[j];
                    temp.second = j;
                }
            }
        }
        if(temp.second != -1)
            dp[i] = temp.first+1;
        else
            dp[i] = 1;
        max = max<dp[i]?dp[i]:max;
    }
    return max;
}