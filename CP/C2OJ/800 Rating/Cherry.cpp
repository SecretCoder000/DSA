long long solve(vector<long long> arr){
    long long ans = LONG_LONG_MIN;
    for(int i = 1;i<arr.size();i++)
        ans = max(ans,arr[i]*arr[i-1]);
    return ans;
}
