int findFloor(vector<long long> v, long long n, long long x){
    int ans = n;
    int lo=0;
    int hi = n-1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(v[mid] == x)
            return mid;
        if(v[mid] < x){
            ans = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return ans==n?-1:ans;
}