bool containsNearbyDuplicate(vector<int>& nums, int k) {
    multiset<int> temp;
    k++;
    for(int i =0;i<nums.size();i++){
        if(temp.size() == k)
            temp.erase(nums[i-k]);
        if(temp.find(nums[i]) != temp.end())
            return true;
        else
            temp.insert(nums[i]);
    }
    return false;
}