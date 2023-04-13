int maxOneIndex(vector<int> & arr,int m) {
    int lo=0;
    int hi = m-1;
    int ans = m;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(arr[mid] == 1){
            ans = min(ans,mid);
            hi=mid-1;
        }else
            lo = mid+1;
    }
    return m-ans;
}
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    pair<int,int> ans = {INT_MIN,-1};
    for(int i =0;i<n;i++){
        int temp = maxOneIndex(arr[i],m);
        if(temp > ans.first && temp != 0)
            ans = {temp,i};
    }
    return ans.second;
}