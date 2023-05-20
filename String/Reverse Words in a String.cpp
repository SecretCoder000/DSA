string reverseWords(string s) {
    string word;
    string ans;
    int n = s.size();
    for(int i = n-1;i>-1;i--){
        if(s[i] == ' ' && !word.empty()){
            if(!ans.empty())
                ans.push_back(' ');
            ans.insert(ans.end(),word.rbegin(),word.rend());
            word.clear();
        }else if(s[i] != ' ')
            word.push_back(s[i]);
    }
    if(!word.empty()){
        if(!ans.empty())
            ans.push_back(' ');
        ans.insert(ans.end(),word.rbegin(),word.rend());
    }
    return ans;
}