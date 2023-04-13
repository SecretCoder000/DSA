string chooseandswap(string a){
    set<int> s;
    int n = a.size();
    for(int i =0;i<n;i++)
        if(s.find(a[i]) == s.end())
            s.insert(a[i]);
    for(int i =0;i<n;i++){
        s.erase(a[i]);
        if(s.empty())
            break;
        char ch = *s.begin();
        if(ch < a[i]){
            char ch2 = a[i];
            for(int j =i;j<n;j++){
                if(a[j]==ch)
                    a[j] = ch2;
                else if(a[j] == ch2)
                    a[j] = ch;
            }
            break;
        }
    }
    return a;
}