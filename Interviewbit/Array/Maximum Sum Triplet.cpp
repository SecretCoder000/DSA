int Solution::solve(vector<int> &arr) {
    int n = arr.size();
    vector<int> rightGreater(n,-1);
    rightGreater[n-1] = arr[n-1];
    for(int i = n-2;i>-1;i--){
        rightGreater[i] = max(rightGreater[i+1],arr[i]);
    }
    set<int> temp;
    temp.insert(arr[0]);
    int ans = 0;
    for(int i =1;i<n-1;i++){
        temp.insert(arr[i]);
        auto it = temp.find(arr[i]);
        if(it != temp.begin() && rightGreater[i] != arr[i])
            ans = max(ans,*(--it)+arr[i]+ rightGreater[i]);
    }
    return ans;
}
