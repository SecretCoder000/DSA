int maxProduct(vector<int>& arr) {
    int n = arr.size();
    int ans,mi,mx;
    mi=mx=ans=arr[0];
    for(int i =1;i<n;i++){
        if(arr[i] < 0)
            swap(mi,mx);
        mx = arr[i]>mx*arr[i]?arr[i]:mx*arr[i];
        mi = arr[i]<mi*arr[i]?arr[i]:mi*arr[i];
        ans = max(mx,ans);
    }
    return ans;
}