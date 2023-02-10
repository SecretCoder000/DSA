#include <bits/stdc++.h>
using namespace std;

int solve(int a,int b,int c){
    int n = abs(a-b)*2;
    if(a > n || b > n || c > n)
        return -1;
    int mid = n/2+1;
    if(c < mid)
        return c+mid-1;
    else
        return (c+mid-1)%n;
}

int main() {
    int t;
    cin>>t;
    while (t--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<solve(a,b,c)<<endl;
    }
}
