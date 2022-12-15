#include<bits/stdc++.h>
using namespace std;

bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    unsigned long long f ,s,t;
    f=s=t=0;
    for(int i =0;i< firstWord.size();i++){
        if(firstWord[i] >= 65 && firstWord[i] <= 90)
            f = f*10+ firstWord[i]-65;
        else
            f = f*10+ firstWord[i]-97;
    }
    for(int i =0;i<secondWord.size();i++){
        if(secondWord[i] >= 65 && secondWord[i] <= 90)
            s = s*10+ secondWord[i]-65;
        else
            s = s*10+ secondWord[i]-97;
    }
    for(int i =0;i<targetWord.size();i++){
        if(targetWord[i] >= 65 && targetWord[i] <= 90)
            t = t*10+ targetWord[i]-65;
        else
            t = t*10+ targetWord[i]-97;
    }
    return f+s==t;
}