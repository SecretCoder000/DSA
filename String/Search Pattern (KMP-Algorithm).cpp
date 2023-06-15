oid findLps(string & str,vector<int> & lps){
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
vector <int> search(string pat, string txt){
    int m = pat.size();
    int n = txt.size();
    vector<int> lps(m,0);
    findLps(pat,lps);
    int i ,j;
    i=j=0;
    vector<int> ans;
    while(j < n){
        if(pat[i] == txt[j]){
            i++;
            j++;
            if(i == pat.size()){
                ans.push_back(j-i+1);
                i=0;
                j -= m-1;
            }
        }else {
            if(i>0)
                i = lps[i-1];
            else
                j++;
        }
    }
    return ans.empty()?vector<int>{-1}:ans;
}