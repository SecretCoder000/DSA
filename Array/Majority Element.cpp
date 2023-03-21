vector<int> majorityElement(vector<int>& nums) {
    map<int,int> temp;
    int n = nums.size();
    int i =0;
    int j = n-1;
    while(i < j){
        temp[nums[i]]++;
        temp[nums[j]]++;
        i++;
        j--;
    }
    if(i == j)
        temp[nums[i]]++;
    vector<int> ans;
    for(auto it : temp)
        if(it.second > n/3)
            ans.push_back(it.first);
    return ans.empty()?vector<int>{}:ans;
}