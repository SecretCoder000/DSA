int maximizeGreatness(vector<int>& nums) {
    vector<int> perm(nums.size());
    map<int,int,greater<int>> temp;
    priority_queue<pair<int,int>> que;
    for(int i =0;i<nums.size();i++){
        temp[nums[i]]++;
        que.push({nums[i],i});
    }
    while (!que.empty()){
        auto it = que.top();
        que.pop();
        if(temp.begin()->first > it.first){
            auto itr = temp.begin();
            perm[it.second] = itr->first;
            itr->second--;
            if(itr->second == 0)
                temp.erase(itr->first);
        }else {
            auto itr = temp.rbegin();
            perm[it.second] = itr->first;
            itr->second--;
            if(itr->second == 0)
                temp.erase(itr->first);
        }
    }
    int ans = 0;
    for(int i =0;i<nums.size();i++){
        if(perm[i] > nums[i])
            ans++;
    }
    return ans;
}