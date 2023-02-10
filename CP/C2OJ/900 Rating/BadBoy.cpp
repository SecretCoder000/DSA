#include <bits/stdc++.h>
using namespace std;

void solve(int n,int m,int i,int j){
    if(i == 1 && j == 1 || i == n && j == m)
        cout<<1<<" "<<m<<" "<<n<<" "<<1<<endl;
    else
        cout<<1<<" "<<1<<" "<<n<<" "<<m<<endl;
}
int main() {
    int t;
    cin>>t;
    while (t--){
        int n,m,i,j;
        cin>>n>>m>>i>>j;
        solve(n,m,i,j);
    }
    return 0;
}