int findKRotation(int arr[], int n) {
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(arr[lo] <= arr[mid]){
            if(mid != n-1 && arr[mid+1] < arr[lo])
                return mid+1;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return 0;
}