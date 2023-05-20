string largestOddNumber(string num) {
    string ans;
    int n = num.size();
    for(int i =n-1;i>-1;i--){
        if((num[i]-48)&1){
            ans = num.substr(0,i+1);
            break;
        }
    }
    return ans;
}