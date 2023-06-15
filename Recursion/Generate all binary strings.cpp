void solve(int & n,string str,vector<string> & ans){
    if(str.size() == n){
        ans.push_back(str);
        return;
    }else {
        if(!str.empty() && str.back() == '1')
            solve(n,str+'0',ans);
        else{
            solve(n,str+"0",ans);
            solve(n,str+"1",ans);
        }
    }
}
void generateBinaryStrings(int num){
    vector<string> ans;
    solve(num,"",ans);
    for(auto it : ans){
        cout<<it<<" ";
    }
}