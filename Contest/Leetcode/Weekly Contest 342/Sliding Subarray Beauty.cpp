vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    vector<int> arr(51,0);
    int n = nums.size();
    vector<int> ans(n-k+1,0);
    for(int i =0;i<n;i++){
        if(nums[i]<0)   arr[-nums[i]]++;
        if(i>=k-1){
            int cnt = 0;
            for(int l = 50;l>0;l--){
                cnt += arr[l];
                if(cnt >= x){
                    ans[i-k+1] = -l;
                    break;
                }
            }
            if(nums[i-k+1] < 0)
                arr[-nums[i-k+1]]--;
        }
    }
    return ans;
}