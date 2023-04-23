int minSubset(vector<int> &arr,int n){
    sort(arr.begin(),arr.end());
    long long sum = 0;
    for(int i =0;i<n;i++)
        sum += arr[i];
    long long temp = 0;
    for(int i = n-1;i>-1;i--){
        temp += arr[i];
        sum -= arr[i];
        if(temp > sum)
            return n-i;
    }
    return 0;
}