string smallestWindow (string s, string t){
    int count,i,j;
    i=j=count=0;
    string str= t;
    pair<int,int> ans = {INT_MAX,0};
    while(j<s.size()){
        if(!str.empty() && str[0] == s[j])
            str.erase(str.begin());
        j++;
        if(str.empty()){
            string temp = t;
            for(int k = j-1;k>=i;k--){
                if(s[k] == temp.back()){
                    temp.erase(temp.back())
                }
            }

        }
    }

    if(ans.first == INT_MAX)
        return "-1";
    return s.substr(ans.second,ans.first);
}