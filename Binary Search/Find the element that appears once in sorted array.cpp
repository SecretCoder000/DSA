int findOnce(int arr[], int n){
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(mid != 0 && arr[mid-1] == arr[mid]){
            if(mid&1)
                lo = mid+1;
            else
                hi = mid-1;
        }else if(mid != n-1 && arr[mid+1] == arr[mid]){
            if((n-mid)&1)
                lo = mid+1;
            else
                hi = mid-1;
        }
        else
            return arr[mid];
    }
    return -1;
}