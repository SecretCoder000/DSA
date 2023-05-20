int Solve(int n, vector<int>& piles, int h) {
    int lo = 1;
    int hi = 1e9;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        int hours = 0;
        for(int i =0;i<n;i++)
            hours += (piles[i]/mid+(piles[i]%mid==0?0:1));
        if(hours <= h)
            hi = mid-1;
        else
            lo = mid+1;
    }
    return lo;
}