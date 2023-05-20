ll floorSqrt(ll x) {
    ll lo = 1;
    ll hi = x;
    while(lo<=hi){
        ll mid = lo+((hi-lo)>>1);
        ll pro = mid*mid;
        if(pro > x)
            hi = mid-1;
        else
            lo = mid+1;
    }
    return hi;
}