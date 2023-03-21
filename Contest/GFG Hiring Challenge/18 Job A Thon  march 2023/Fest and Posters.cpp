long long minimumTime(int n, int num, vector<int> &time) {
    long long r = 1e18;
    long long l = 0;
    long long mn = LONG_LONG_MAX;
    while (l<r){
        long long mid = (l+r)/2;
        long long sum = 0;
        for(auto it : time){
            sum += mid/it;
        }
        if(sum >= num){
            r = mid;
            mn = min(mn,mid);
        }else
            l = mid+1;
    }
    return mn;
}