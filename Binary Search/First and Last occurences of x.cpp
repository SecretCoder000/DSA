int findFirst(int arr[],int n,int k){
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(arr[mid]<k)
            lo = mid+1;
        else {
            if(arr[mid] == k)
                ans = mid;
            hi = mid-1;
        }
    }
    return ans;
}
int findLast(int arr[],int n,int k){
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(arr[mid]<=k) {
            if (arr[mid] == k)
                ans = mid;
            lo = mid + 1;
        }else
            hi = mid-1;
    }
    return ans;
}
vector<int> find(int arr[], int n , int x ){
    int f = findFirst(arr,n,x);
    int s = findLast(arr,n,x);
    return {f,s};
}