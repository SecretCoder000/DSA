void findLps(string & str,vector<int> & lps){
    int l = 0;
    int r = 1;
    while(r<str.size()){
        if(str[l] == str[r]){
            lps[r] = l+1;
            l++;
            r++;
        }else {
            if(l > 0)
                l = lps[l-1];
            else
                r++;
        }
    }
}
int search(string pat, string txt){
    int m = pat.size();
    int n = txt.size();
    vector<int> lps(m,0);
    findLps(pat,lps);
    int i ,j;
    i=j=0;
    while(j < n){
        if(pat[i] == txt[j]) {
            i++;
            j++;
            if (i == pat.size()) {
                i = 0;
                j = j - i + 1;
            }
        }else {
            if(i>0)
                i = lps[i-1];
            else
                j++;
        }
    }
    if(i==0)
        return 0;
    return n-i;
}
int minChar(string str){
    string strrev = str;
    reverse(str.begin(),str.end());
    return search(strrev,str);
}