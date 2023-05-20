#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a[n];
        int big=1;
        cin>>a[0];
        for(int i =1;i<n;++i){
            cin>>a[i];
            if(a[big] < a[i])
                big = i;
        }
        if(big == n-1){
            cout<<a[big]<<" ";
            for(int i =0;i<n-1;++i)
                cout<<a[i]<<" ";
            cout<<endl;
            continue;
        }
        int s = 0;
        for(int i =1;i<big;++i){
            if(a[s] < a[i])
                s = i;
        }
        for(int i = big;i<n;++i)
            cout<<a[i]<<" ";
        if(s == 0){
            cout<<a[big-1]<<" ";
            for(int i =0;i<big-1;++i)
                cout<<a[i]<<" ";
        }else {
            for(int i = big-1;i>=s;--i)
                cout<<a[i]<<" ";
            for(int i = 0;i<s;++i)
                cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}