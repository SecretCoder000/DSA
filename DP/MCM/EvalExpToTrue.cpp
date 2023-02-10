#include <bits/stdc++.h>
using namespace std;
int solve(string str,int i,int j,bool isTrue){
    if(i>j)
        return false;
    else if (i == j){
        if(isTrue)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }
    int ans = 0;
    for(int k =i+1;k<j;k+=2){
        int lT = solve(str,i,k-1,true);
        int lF = solve(str,i,k-1,false);
        int rT = solve(str,k+1,j,true);
        int rF = solve(str,k+1,j,false);
        switch(str[k]){
            case '&':
                if(isTrue)
                    ans = ans +  rT*lT;
                else
                    ans = ans + rF*lT + rT*lF + rF*lF;
                break;
            case '|':
                if(isTrue)
                    ans = ans + rF*lT + rT*lF + rT*lT;
                else
                    ans = ans + rF*lF;
                break;
            case '^' :
                if(isTrue)
                    ans = ans + rF*lT + lF*rT;
                else
                    ans = ans + rT*lT + rF*lF;
                break;
        }
    }
    return ans;
}
ll solve(string str,ll i,ll j,bool isTrue,map<string,ll> & dp){
    if(i>j)
        return true;
    else if (i == j){
        if(isTrue)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }
    string key = to_string(i) +" " + to_string(j)+" " + to_string(isTrue);
    if(dp.find(key) != dp.end())
        return dp[key];
    ll ans = 0;
    for(ll k =i+1;k<j;k+=2){
        ll lT = solve(str,i,k-1,true,dp);;
        ll lF = solve(str,i,k-1,false,dp);
        ll rT = solve(str,k+1,j,true,dp);
        ll rF = solve(str,k+1,j,false,dp);
        switch(str[k]){
            case '&':
                if(isTrue)
                    ans = ans +  rT*lT;
                else
                    ans = ans + rF*lT + rT*lF + rF*lF;
                break;
            case '|':
                if(isTrue)
                    ans = ans + rF*lT + rT*lF + rT*lT;
                else
                    ans = ans + rF*lF;
                break;
            case '^' :
                if(isTrue)
                    ans = ans + rF*lT + lF*rT;
                else
                    ans = ans + rT*lT + rF*lF;
                break;
        }
    }
    dp[key] = ans;
    return ans;
}
int main() {
    string str = "F^F&T&F^T|T^F^T^F^T&F^F^T|F|T|F&F&F|F|T&F|F&F^T&F&F^T|T|T|T^T&T|T^F&T|T^F&T|T^F&T&F|T|T^T&F&T|T&F^F";
    map<string,ll> dp;
    cout<<solve(str,0,str.size()-1,true,dp);
    return 0;
}
