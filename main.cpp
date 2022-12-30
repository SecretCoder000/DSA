#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    while ((n & n-1) > 0)
        n--;
    return n-1;
}

int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}