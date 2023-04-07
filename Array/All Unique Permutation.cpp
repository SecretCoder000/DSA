void solve(vector<int> arr,vector<vector<int>> & ans,int ind){
    if(arr.size() == ind){
        ans.push_back(arr);
        return;
    }
    for(int i =ind;i<arr.size();i++){
        if(i != ind && arr[i] == arr[ind])
            continue;
        swap(arr[i],arr[ind]);
        solve(arr,ans,ind+1);
    }
}
vector<vector<int>> uniquePerms(vector<int> nums,int n) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    solve(nums,ans,0);
    return ans;
}