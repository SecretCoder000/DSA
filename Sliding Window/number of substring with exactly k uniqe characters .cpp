ll mostKCharacters(string s,int k){
    if(s.empty() || k == 0)
        return 0;
    vector<int> temp(26);
    int n = s.size();
    int i,j;
    ll count=0;
    i=j=0;
    int size=0;
    while(j < n){
        if(temp[s[j]-'a'] == 0)
            size++;
        temp[s[j]-'a']++;
        if(size > k){
            while(i < j && size > k){
                temp[s[i]-'a']--;
                if(temp[s[i]-'a'] == 0)
                    size--;
                i++;
            }
        }
        count += ((j-i)+1);
        j++;
    }
    return count;
}
ll substrCount (string s, int k) {
    return mostKCharacters(s,k)-mostKCharacters(s,k-1);
}