string Solution::solve(string s) {
    int n = s.size();
    int index = -1;
    for(int i =n-2;i>=0;--i){
        if(s[i] < s[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1)
        return "-1";
    int greaterIndex = -1;
    for(int i = n-1;i >index;--i){
        if(s[i] > s[index]){
            greaterIndex = i;
            break;
        }
    }
    swap(s[index],s[greaterIndex]);
    sort(s.begin()+index+1,s.end());
    return s;

}