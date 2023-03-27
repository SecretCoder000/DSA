vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    set<vector<int>> ans;
    for(int i =0;i<n-2;i++){
        int sum = -nums[i];
        int l = i+1;
        int r = n-1;
        while(l<r){
            int temp2 = nums[l] + nums[r];
            if(temp2 == sum){
                ans.insert({nums[i],nums[l],nums[r]});
                l++;
                r--;
            }else if(temp2 > sum)
                r--;
            else
                l++;
        }
    }
    return vector<vector<int>> {ans.begin(),ans.end()};
}