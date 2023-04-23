long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long ans = LONG_LONG_MAX;
    for(int i = m-1;i<n;i++){
        long long temp =  abs(a[i]-a[i-m+1]);
        if(ans > temp )
            ans = temp;
    }
    return ans;
}