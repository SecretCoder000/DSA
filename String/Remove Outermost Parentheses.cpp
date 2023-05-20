string removeOuterParentheses(string s) {
    string str;
    string ans;
    int count = 0;
    for(auto it : s){
        if(it == '('){
            if(count > 0)
                str.push_back(it);
            count++;
        }else{
            if(count>1)
                str.push_back(it);
            count--;
        }
        if(count==0){
            ans.insert(ans.end(),str.begin(),str.end());
            str.clear();
        }
    }
    return ans;
}