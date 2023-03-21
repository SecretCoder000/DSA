vector<int> findDifferenceArray(int n, vector<int> &arr) {
    map<int,int> left,right;
    for(int i =1;i<n;i++)
        right[arr[i]]++;
    vector<int> ans(n);
    for(int i =0;i<n-1;i++){
        int l = left.empty()?0:left.begin()->first;
        int r = right.begin()->first;
        ans[i] = l-r;
        left[arr[i]]++;
        right[arr[i+1]]--;
        if(right[arr[i+1]] == 0)
            right.erase(arr[i+1]);
    }
    ans[n-1] = left.begin()->first;
    return ans;
}