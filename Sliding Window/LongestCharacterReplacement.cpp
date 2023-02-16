int characterReplacement(string s, int k) {
    int i;
    i=0;
    pair<char,int> max={s[0],1};
    map<char,int> temp;
    int ans = 0;
    for(int j =0;j<s.size();j++){
        temp[s[j]]++;
        int max = 0;
        for(auto itr = temp.begin();itr != temp.end();itr++)
            max = max<itr->second?itr->second:max;
        if(j-i+1-max > k){
            temp[s[i]]--;
            if(temp[s[i]] == 0)
                temp.erase(temp.find(s[i]));
            i++;
        }
        ans = ans<(j-i+1)?(j-i+1):ans;
    }
    return ans;
}