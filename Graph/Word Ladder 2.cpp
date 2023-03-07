vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& List) {
    if(startWord == targetWord)
        return {{startWord}};
    set<string> wordList={List.begin(),List.end()};
    vector<string> usedLevel={startWord};
    queue<vector<string>> que;
    que.push({startWord});
    vector<vector<string>> ans;
    int level = 0;
    while (!que.empty()){
        vector<string> str = que.front();
        que.pop();
        if(str.size() > level){
            level++;
            for(auto it : usedLevel)
                wordList.erase(it);
            usedLevel.clear();
        }
        if(str.back() == targetWord){
            if(ans.size() == 0)
                ans.push_back(str);
            else if(ans[0].size() == str.size())
                ans.push_back(str);
        }
        for(int i =0;i<str.back().size();i++){
            for(int j =0;j<26;j++){
                string temp = str.back();
                temp[i] = 97+j;
                if(wordList.find(temp) != wordList.end() ){
                    vector<string> temp2 = str;
                    temp2.push_back(temp);
                    que.push(temp2);
                    usedLevel.push_back(temp);
                }
            }
        }
    }
    return ans;
}