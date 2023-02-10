long maximumSumSubarray(int k, vector<int> &arr , int n){
    long sum = 0;

    for(int i =0;i<k;i++)
        sum += arr[i];
    long ans = sum;
    for(int i = k;i<n;i++){
        sum -= arr[i-k];
        sum += arr[i];
        ans = max(sum,ans);
    }
    return ans;
}