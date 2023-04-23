string rearrangeString(string str){
    vector<int> temp(26);
    int n = str.size();
    for(int i =0;i<n;i++){
        temp[str[i]-'a']++;
    }
    priority_queue<pair<int,char>> que;
    for(int i =0;i<26;i++){
        if(temp[i] > 0)
            que.push({temp[i],i+'a'});
    }
    string ans;
    while(que.size() > 1){
        auto f = que.top();
        que.pop();
        auto s = que.top();
        que.pop();
        ans.push_back(f.second);
        ans.push_back(s.second);
        if(f.first > 1)
            que.push({f.first-1,f.second});
        if(s.first > 1)
            que.push({s.first-1,s.second});
    }
    if(que.size() == 1){
        auto it = que.top();
        if(it.first > 1)
            return "-1";
        ans.push_back(it.second);
    }
    return ans;
}