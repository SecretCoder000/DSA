#include<bits/stdc++.h>
using namespace std;
string makeGood(string s) {
    if(s.empty())
        return "";
    bool flag = false;
    for(int i =0;i<s.size()-1;i++){
        if(s[i] == s[i+1]-32 || s[i] == s[i+1]+32) {
            s.erase(s.begin()+i);
            s.erase(s.begin()+i);
            flag = true;
            break;
        }
    }
    if(flag)
        return makeGood(s);
    return s;
}
