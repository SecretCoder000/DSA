int countSubstring(string s) {
    int i,j,sum;
    i=j=sum=0;
    map<char,int> temp;
    while(j<s.size()){
        if(temp.size() < 3){
            temp[s[j]]++;
            j++;
        }
        if(temp.size() == 3){
            sum += (s.size()-j+1);
            temp[s[i]]--;
            if(temp[s[i]] == 0)
                temp.erase(temp.find(s[i]));
            i++;
        }
    }
    while(i<s.size() && temp.size() == 3){
        sum += (s.size()-j+1);
        temp[s[i]]--;
        if(temp[s[i]] == 0)
            temp.erase(temp.find(s[i]));
        i++;
    }
    return sum;
}