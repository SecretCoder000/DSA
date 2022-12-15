#include<bits/stdc++.h>
using namespace std;
double myPow(double x,int n){
    double ans = 1.0;
    long long nn = n;
    if(n<0)
        nn = nn*(-1);
    while(nn){
        if(nn%2){
            ans *= x;
            nn--;
        }else {
            x *= x;
            nn /= 2;
        }
    }
    if(n<0) ans = (double)(1.0)/(double)(ans);
    return ans;
}