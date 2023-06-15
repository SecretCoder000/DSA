void solve(int o,int c,string str,vector<string> & ans){
    if(o == 0 && c ==0){
        ans.push_back(str);
        return;
    }else {
        if(o == c)
            solve(o-1,c,str+"(",ans);
        else if(o < c){
            if(o > 0)
                solve(o-1,c,str+"(",ans);
            if(c > 0)
                solve(o,c-1,str+")",ans);
        }
    }
}
vector<string> AllParenthesis(int n) {
    vector<string> ans;
    solve(n,n,"",ans);
    return ans;
}