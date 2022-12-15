#include<bits/stdc++.h>
using namespace std;
void solve(string s,int k,int size,int & ans){
    if(s.empty())
        ans = ans<size?ans:size;
    else {
        solve(s.data()+1,k-1,size+1,ans);
        if(k == 0)  
            return;
        int count = 1;
        for(int i = 0;i<s.size()-1;i++){
            if(s[i] == s[i+1])
                count++;
            else 
                break;
        }
        if(count == 1){
            solve(s.data()+1,k-1,size+1,ans);
        }else {
            if(count )
            solve(s.data()+count,k,size,ans);
        }
    }
}
int getLengthOfOptimalCompression(string s, int k) {
    int count = 1;
    string temp;
    priority_queue<pair<int,pair<char,int>>> que;
    for(int i =1;i<s.size();i++){
        if(s[i-1] == s[i])
            count++;
        else {
            temp.push_back(s[i-1]);
            temp.append(to_string(count));
            count = 1;
        }
        if(i == s.size()-1){
            temp.push_back(s[i]);
            temp.append(to_string(count));
        }
    }
    string str;
    string num;
    for(int i =temp.size()-1;i>-1;i--){
        if(temp[i] >= 49 && temp[i] <= 57){
            num.insert(num.begin(),temp[i]);
        }else {
            que.push({stoi(num),{temp[i],i}});
        }
    }

}