int longestKSubstr(string s, int k) {
    map<char,int> temp;
    int i,j;
    i=j=0;
    int n = s.size();
    int ans = -1;
    while(j<n){
        temp[s[j]]++;
        while(temp.size() > k){
            temp[s[i]]--;
            if(temp[s[i]] == 0)
                temp.erase(s[i]);
            i++;
        }
        if(temp.size() == k)
            ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}

