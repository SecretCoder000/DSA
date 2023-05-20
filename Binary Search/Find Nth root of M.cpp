int NthRoot(int n, int x){
    int lo = 1;
    int hi = x;
    int ans = -1;
    while(lo<=hi){
        int mid = lo+((hi-lo)>>n);
        long long pro = 1;
        for(int i =0;i<n;i++){
            pro *= mid;
            if(pro > INT_MAX)
                break;
        }
        if(pro > x)
            hi = mid-1;
        else {
            if(pro==x)
                ans = mid;
            lo = mid+1;
        }
    }
    return ans;
} 