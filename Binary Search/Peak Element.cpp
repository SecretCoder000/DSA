int peakElement(int a[], int n){
    int lo;
    int hi=n-1;
    while(lo<hi){
        int mid  = (lo+hi)>>1;
        if(a[mid] >= a[mid+1])
            hi = mid;
        else
            lo= mid+1;
    }
    return hi;
}