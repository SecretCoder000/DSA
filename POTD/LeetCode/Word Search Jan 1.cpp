bool wordPattern(string pattern, string s){
    map<char,string> temp;
    map<string,char> match;
    int j = 0;
    string res="";
    for(int i =0;i<pattern.size() && j<s.size();i++){
        string word;
        for(int k = j;k<s.size() && s[k] != ' ';k++,j++)
            word.push_back(s[k]);
        j++;
        auto itr = temp.find(pattern[i]);
        auto itr2 = match.find(word);
        if((itr != temp.end() && itr2 ==match.end()) || (itr == temp.end() && itr2 != match.end()))
            return false;
        else if(itr == temp.end() && itr2 == match.end()){
            temp.insert({pattern[i],word});
            match.insert({word,pattern[i]});
            itr = temp.find(pattern[i]);
            res.push_back(itr->first);
        }else if(itr->first != itr2->second || itr->second != itr2->first)
            return false;
        else
            res.push_back(itr->first);
    }
    if(j-1 < s.size())
        return false;
    return res == pattern;
}