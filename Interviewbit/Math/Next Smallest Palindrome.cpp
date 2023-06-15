string increment(int n){
    string str;
    str.push_back('1');
    for(int i =1;i<n;++i)
        str.push_back('0');
    str.push_back('1');
    return str;
}
string Solution::solve(string s) {
    int n = 0;
    for(auto it : s){
        if(it == '9')
            n++;
    }
    if(n == s.size())
        return increment(n);
    n = s.size();
    string prefix,suffix;
    prefix = s.substr(0,n/2);
    reverse(prefix.begin(),prefix.end());
    suffix = s.substr((n+1)/2);
    if(prefix > suffix){
        string ans = s.substr(0,n/2);
        if(n&1)
            ans.push_back(s[n/2]);
        ans.insert(ans.end(),prefix.begin(),prefix.end());
        return ans;
    }
    int index = -1;
    for(int i = (n+1)/2-1;i>-1;--i){
        if(s[i] < '9'){
            index = i;
            break;
        }
    }
    if(index != -1){
        s[index]= s[index]+1;
        if(index != (n+1)/2){
            for(int i = index+1;i<(n+1)/2;++i)
                s[i] ='0';
        }
        string ans = s.substr(0,(n+1)/2);
        for(int i = n/2-1;i>=0;--i)
            ans.push_back(ans[i]);
        return ans;
    }else {
        string str(n,'9');
        return str;
    }
}
