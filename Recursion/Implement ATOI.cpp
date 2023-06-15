int solve(int i ,string str){
    if(i < 0 )
        return 0;
    if(!(str[i] >= '0' && str[i] <= '9'))
        return -1;
    int ans = solve(i-1,str);
    if(ans == -1)
        return ans;
    return (str[i]-'0')+ans*10;
}
int atoi(string str) {
    bool  flag = false;
    if(str[0] == '-'){
        flag = true;
        str = str.substr(1);
    }
    int ans =  solve(str.size()-1,str);
    if(ans == -1)
        return ans;
    return ans*(flag?-1:1);
}