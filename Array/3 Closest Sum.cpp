int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    pair<int,int> ans = {INT_MAX,0};
    sort(nums.begin(),nums.end());
    for(int i =0;i<n;i++){
        int l = i+1;
        int r = n-1;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            int diff = abs(sum-target);
            if(diff == 0)
                return sum;
            else if(diff < ans.first)
                ans = {diff,sum};
            if(sum > target)
                r--;
            else
                l++;
        }
    }
    return ans.second;
}