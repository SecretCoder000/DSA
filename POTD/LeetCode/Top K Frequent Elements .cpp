vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> temp;
    for(auto it : nums){
        temp[it]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    for(auto itr : temp){
        que.push({itr.second,itr.first});
        if(que.size() > k)
            que.pop();
    }
    vector<int> ans;
    while (!que.empty()){
        ans.push_back(que.top().second);
        que.pop();
    }
    return ans;

}