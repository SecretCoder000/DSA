#include<bits/stdc++.h>
#include "LinkedList/linkedlist.h"
using namespace std;
string reverseVowels(string s) {
    int lo,hi;
    int l,r;
    lo = 0;
    hi = s.size()-1;
    l=r=-1;
    while(lo < hi){
        if(l == -1){
            switch (s[lo]) {
                case 'a':case 'e':case 'i':case 'o':case 'u':case 'A':case 'E':case 'I':case 'O':case 'U':
                    l = lo;
            }
            lo++;
        }else if(r == -1){
            switch (s[hi]) {
                case 'a':case 'e':case 'i':case 'o':case 'u':case 'A':case 'E':case 'I':case 'O':case 'U':
                    r = hi;
            }
            hi--;
        }
        if ( l != -1 && r != -1 ){
            swap(s[l],s[r]);
            l = r= -1;
        }
    }
    return s;
}

