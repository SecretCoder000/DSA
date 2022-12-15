#include "bits/stdc++.h"
using namespace std;
string removeDuplicates(string s) {
    int i =0;
    int k = s.size()-1;
    while (i<k){
        if(s[i] == s[i+1]){
            s.erase(s.begin()+i);
            s.erase(s.begin()+i);
            if(i != 0)
                i--;
            k = s.size()-1;
        }else
            i++;
    }
    return s;
}