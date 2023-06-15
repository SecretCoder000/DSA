string lookandsay(int n) {
    string str="1";
    while(--n){
        int count = 1;
        string newStr;
        for(int i =1;i<str.size();i++){
            if(str[i] == str[i-1])
                count++;
            else {
                string temp = to_string(count);
                newStr.insert(newStr.end(),temp.begin(),temp.end());
                newStr.push_back(str[i-1]);
                count=1;
            }
        }
        string temp = to_string(count);
        newStr.insert(newStr.end(),temp.begin(),temp.end());
        newStr.push_back(str[str.size()-1]);
        str = newStr;
    }
    return str;
}