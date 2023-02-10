#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        ll s = max(n/2020,n/2021);
        bool flag = false;
        for(int i = 0;i<=s;i++) {
            if (i * 2021 + (s - i) * 2020 == n) {
                flag = true;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
