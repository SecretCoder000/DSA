#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool solve(string a, string b){
    if(a.size() != b.size())
        return false;
    if(a == b)
        return true;
    int n = a.size();
    for(int i = 1;i<a.size();i++){
        if(solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))
            return true;
        if(solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)))
            return true;
    }
    return false;
}

bool solve(string a,string b,map<string,bool> & dp){

    if(a.size() != b.size())
        return false;
    if(a == b)
        return true;
    string key = a + " "+b;
    if(dp.find(key) !=  dp.end())
        return dp[key];
    int n = a.size();
    bool flag = false;
    for(int i = 1;i<n;i++){
        if(solve(a.substr(0,i),b.substr(0,i),dp) && solve(a.substr(i,n-i),b.substr(i,n-i),dp)){
            flag = true;
            break;
        }
        if(solve(a.substr(0,i),b.substr(n-i,i),dp) && solve(a.substr(i,n-i),b.substr(0,n-i),dp)){
            flag = true;
            break;
        }
    }
    dp[key] = flag;
    return flag;
}

int main() {
    string a = "coder";
    string b = "ocder";
    map<string,bool> dp;
    cout<<solve(a,b,dp);

    return 0;
}

