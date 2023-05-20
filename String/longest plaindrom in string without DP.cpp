//Best Approach two pointer
string longestPalindrome(string s) {
    int maxLen,start;
    maxLen = 0;
    int n = s.size();
    for(int i =0;i<n;){
        if(n-i < maxLen/2)
            break;
        int l,r;
        l=r=i;
        while(r<n-1 && s[r] == s[r+1])
            r++;
        i = r+1;
        while(l > 0 && r < n && s[l-1] == s[r+1]){
            l--;
            r++;
        }
        int newLen = r-l+1;
        if(maxLen < newLen){
            maxLen = newLen;
            start = l;
        }
    }
    return s.substr(start,maxLen);
}

//Brute force
bool checkPlaindrom(string s){
    int i = 0;
    int n = s.size();
    while(i<n/2){
        if(s[i] != s[n-i-1])
            return false;
        i++;
    }
    return true;
}
string longestPalin (string s) {
    string ans ;
    int n = s.size();
    for(int i =n;i>=1 && i > ans.size();i--){
        string str = s.substr(0,i);
        if(checkPlaindrom(str)){
            ans = str;
            continue;
        }
        for(int j = i;j<n;j++){
            str.erase(str.begin());
            str.push_back(s[j]);
            if(checkPlaindrom(str)){
                ans = str;
                break;
            }
        }
    }
    return ans;
}

