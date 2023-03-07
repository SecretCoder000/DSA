bool compare(string str1,string str2){
    int count = 0;
    for(int i =0;i<str1.size();i++){
        if(str1[i] != str2[i])
            count++;
        if(count > 1)
            return false;
    }
    return true;
}
int ladderLength(string startWord, string targetWord, vector<string>& List) {
    if(startWord == targetWord)
        return 0;
    set<string> wordList;
    for(int i =0;i<List.size();i++)
        wordList.insert(List[i]);
    set<string> vis;
    queue<pair<string,int>> que;
    que.push({startWord,0});
    vis.insert(startWord);
    while (!que.empty()){
        string str = que.front().first;
        int dist = que.front().second;
        que.pop();
        for(int i =0;i<str.size();i++){
            for(int j =0;j<26;j++){
                string temp = str;
                temp[i] = 97+j;
                if(wordList.find(temp) != wordList.end() && vis.find(temp) == vis.end()){
                    que.push({temp,dist+1});
                    vis.insert(temp);
                }
            }
        }
        if(vis.find(targetWord) != vis.end())
            return dist+2;
    }
    return 0;
}