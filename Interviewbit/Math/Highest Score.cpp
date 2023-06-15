int highestScore(vector<vector<string> > &a) {
    unordered_map<string,pair<int,int>> temp;
    for(auto it : a){
        string name = it[0];
        int marks = stoi(it[1]);
        auto itr = temp.find(name);
        if(itr == temp.end())
            temp[name] = {marks,1};
        else{

            temp[name] = {itr->second.first+marks,itr->second.second+1};
        }
    }
    int ans = INT_MIN;
    for(auto itr : temp)
        ans = max(ans,(int)itr.second.first/itr.second.second);
    return ans;
}