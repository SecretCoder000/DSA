void solve(string s,int i,string str,vector<string> & ans){
    if(i == s.size()){
        if(!str.empty())
            ans.push_back(str);
    }else {
        solve(s,i+1,str+s[i],ans);
        solve(s,i+1,str,ans);
    }
}
vector<string> AllPossibleStrings(string s){
    vector<string> ans;
    solve(s,0,"",ans);
    sort(ans.begin(),ans.end());
    return ans;
}