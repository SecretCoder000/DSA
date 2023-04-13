int searchInsertK(vector<int>arr, int n, int k){
    if(k <= arr[0])
        return 0;
    else if(arr[n-1] == k)
        return n-1;
    else if(k>arr[n-1])
        return n;
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(arr[mid] == k)
            return mid;
        else if(arr[mid] < k)
            lo = mid+1;
        else {
            ans = mid;
            hi = mid-1;
        }
    }
    return ans;
}