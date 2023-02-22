long long maxScore(vector<int> &arr, int N, int k) {
    long long sum =0;
    for(int i =0;i<N;i++)
        sum += arr[i];
    if(k == 0)
        return 0;
    if(k == N)
        return sum;
    long long ans  = 0;
    long long temp = 0;
    for(int i =0;i<N;i++){
        temp += arr[i];
        if((i+1)>=(N-k)){
            ans = max(ans,sum-temp);
            temp -= arr[i+1-N+k];
        }
    }
    return ans;
}
