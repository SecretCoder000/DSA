int lps(string s) {
    int n = s.size();
    vector<int> arr(n,0);
    int l,r;
    l=0;r=1;
    int ans = 0;
    while(r<n){
        if(s[l] == s[r]){
            arr[r++] = ++l;
            ans = max(ans,arr[r-1]);
        }else {
            if(l>0)
                l = arr[l-1];
            else
                r++;
        }
    }
    return arr[n-1];
}