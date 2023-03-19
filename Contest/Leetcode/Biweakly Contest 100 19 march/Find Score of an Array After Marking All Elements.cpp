long long findScore(vector<int>& nums) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
    set<int> vis;
    for(int i =0;i<nums.size();i++)
        heap.push({nums[i],i});
    long long score = 0;
    while (!heap.empty()){
        auto it = heap.top();
        heap.pop();
        if(vis.find(it.second) == vis.end()){
            score+= it.first;
            vis.insert(it.second);
            if(it.second != 0)
                vis.insert(it.second-1);
            if(it.second != nums.size()-1)
                vis.insert(it.second+1);
        }
    }
    return score;
}